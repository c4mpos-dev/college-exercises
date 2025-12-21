"use client"

import type React from "react"

import { useState, useEffect, useRef } from "react"

interface ChatModalProps {
  isOpen: boolean
  onClose: () => void
  contactName: string
  contactType: string
}

interface Message {
  id: number
  text: string
  sender: "user" | "contact"
  timestamp: string
}

export default function ChatModal({ isOpen, onClose, contactName, contactType }: ChatModalProps) {
  const [messages, setMessages] = useState<Message[]>([])
  const [inputMessage, setInputMessage] = useState("")
  const messagesEndRef = useRef<HTMLDivElement>(null)

  useEffect(() => {
    if (isOpen) {
      // Mensagem de boas-vindas automática
      setMessages([
        {
          id: 1,
          text: `Olá! Sou ${contactName}. Como posso ajudá-lo?`,
          sender: "contact",
          timestamp: new Date().toLocaleTimeString("pt-BR", { hour: "2-digit", minute: "2-digit" }),
        },
      ])
    } else {
      setMessages([])
      setInputMessage("")
    }
  }, [isOpen, contactName])

  useEffect(() => {
    messagesEndRef.current?.scrollIntoView({ behavior: "smooth" })
  }, [messages])

  const handleSendMessage = () => {
    if (inputMessage.trim() === "") return

    const userMessage: Message = {
      id: messages.length + 1,
      text: inputMessage,
      sender: "user",
      timestamp: new Date().toLocaleTimeString("pt-BR", { hour: "2-digit", minute: "2-digit" }),
    }

    setMessages([...messages, userMessage])
    setInputMessage("")

    // Simula resposta automática após 1.5 segundos
    setTimeout(() => {
      const autoResponses = [
        "Obrigado pela mensagem! Vou verificar isso para você.",
        "Entendi sua solicitação. Aguarde um momento, por favor.",
        "Certo! Vou providenciar isso o mais breve possível.",
        "Pode deixar! Irei resolver essa questão hoje mesmo.",
        "Sua solicitação foi registrada. Em breve retorno com mais informações.",
      ]

      const randomResponse = autoResponses[Math.floor(Math.random() * autoResponses.length)]

      const contactMessage: Message = {
        id: messages.length + 2,
        text: randomResponse,
        sender: "contact",
        timestamp: new Date().toLocaleTimeString("pt-BR", { hour: "2-digit", minute: "2-digit" }),
      }

      setMessages((prev) => [...prev, contactMessage])
    }, 1500)
  }

  const handleKeyPress = (e: React.KeyboardEvent<HTMLInputElement>) => {
    if (e.key === "Enter") {
      handleSendMessage()
    }
  }

  if (!isOpen) return null

  return (
    <>
      {/* Overlay */}
      <div className="fixed inset-0 bg-black/50 backdrop-blur-sm z-50 animate-fadeIn" onClick={onClose} />

      {/* Chat Modal */}
      <div className="fixed inset-0 z-50 flex items-center justify-center p-4 pointer-events-none">
        <div
          className="bg-back2 rounded-2xl shadow-2xl w-full max-w-md h-[600px] overflow-hidden pointer-events-auto animate-slideUp flex flex-col"
          onClick={(e) => e.stopPropagation()}
        >
          {/* Header */}
          <div className="bg-linear-to-r from-[#006FC9] to-[#005099] px-5 py-4 flex items-center justify-between text-white">
            <div className="flex items-center gap-3">
              <div className="w-10 h-10 rounded-full bg-back2/20 flex items-center justify-center">
                <span className="material-symbols-outlined text-2xl">person</span>
              </div>
              <div>
                <h3 className="font-bold text-sm">{contactName}</h3>
                <p className="text-xs opacity-90">{contactType}</p>
              </div>
            </div>
            <button onClick={onClose} className="text-white/90 hover:text-white transition-colors">
              <span className="material-symbols-outlined text-2xl">close</span>
            </button>
          </div>

          {/* Messages Area */}
          <div className="flex-1 overflow-y-auto p-4 bg-gray-50 space-y-3">
            {messages.map((message) => (
              <div key={message.id} className={`flex ${message.sender === "user" ? "justify-end" : "justify-start"}`}>
                <div
                  className={`max-w-[75%] rounded-2xl px-4 py-2 ${
                    message.sender === "user"
                      ? "bg-[#006FC9] text-white rounded-br-none"
                      : "bg-back2 text-text rounded-bl-none shadow-sm"
                  }`}
                >
                  <p className="text-sm">{message.text}</p>
                  <p className={`text-[10px] mt-1 ${message.sender === "user" ? "text-white/70" : "text-text/60"}`}>
                    {message.timestamp}
                  </p>
                </div>
              </div>
            ))}
            <div ref={messagesEndRef} />
          </div>

          {/* Input Area */}
          <div className="p-4 bg-back2 border-t border-gray-200">
            <div className="flex gap-2">
              <input
                type="text"
                value={inputMessage}
                onChange={(e) => setInputMessage(e.target.value)}
                onKeyPress={handleKeyPress}
                placeholder="Digite sua mensagem..."
                className="flex-1 px-4 py-2 border border-gray-300 rounded-full text-sm focus:outline-none focus:ring-2 focus:ring-[#006FC9] focus:border-transparent"
              />
              <button
                onClick={handleSendMessage}
                className="w-10 h-10 bg-[#006FC9] hover:bg-[#005099] text-white rounded-full flex items-center justify-center transition-colors"
              >
                <span className="material-symbols-outlined text-xl">send</span>
              </button>
            </div>
          </div>
        </div>
      </div>
    </>
  )
}
