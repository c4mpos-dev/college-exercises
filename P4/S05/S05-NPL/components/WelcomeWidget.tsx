"use client"

import Image from "next/image";
import { useEffect, useState } from "react"

interface Message {
  icon: string
  text: string
  type: "warning" | "info" | "success"
}

interface WelcomeWidgetProps {
  userName: string
}

const messages: Message[] = [
  { icon: "notifications_active", text: "Você possui um armário reservado com entrega para hoje", type: "info" },
  { icon: "warning", text: "Você possui uma pendência no financeiro", type: "warning" },
  { icon: "schedule", text: "Prova de Circuitos Elétricos amanhã às 10:00", type: "warning" },
]

export default function WelcomeWidget({ userName }: WelcomeWidgetProps) {
  const alertConfig: Record<string, { color: string }> = {
    warning: { color: '#f97316' },
    success: { color: '#16a34a' },
    info: { color: '#0ea5e9' },
  }

  const [isDark, setIsDark] = useState(false)

  useEffect(() => {
    const detect = () => setIsDark(document.documentElement.classList.contains('dark'))
    detect()
    const obs = new MutationObserver(detect)
    obs.observe(document.documentElement, { attributes: true, attributeFilter: ['class'] })
    return () => obs.disconnect()
  }, [])

  const currentHour = new Date().getHours()
  const greeting = currentHour < 12 ? "Bom dia" : currentHour < 18 ? "Boa tarde" : "Boa noite"

  return (
    <div className="bg-back2 rounded-2xl shadow-md p-6 border border-border">
      <div className="flex items-center gap-3 mb-4">
        <div className="flex items-center justify-center w-12 h-12 rounded-full border-2 border-border">
          <Image src="/Raphael.png" alt="User Icon" width={50} height={50} className="rounded-full"/>
        </div>
        <div>
          <h2 className="font-sans font-bold text-2xl text-text">
            {greeting}, {userName}!
          </h2>
          <p className="font-sans text-sm text-text opacity-80">Aqui está o resumo do seu dia</p>
        </div>
      </div>

      <div className="space-y-3">
        {messages.map((msg, idx) => {
          const cfg = alertConfig[msg.type] ?? alertConfig.info
          const defaultColor = cfg.color
          const borderColor = isDark ? '#9ca3af' : defaultColor
          const bg = isDark ? 'var(--cor-back1)' : `color-mix(in srgb, ${defaultColor} 8%, var(--cor-back2))`
          return (
            <div
              key={idx}
              className={`rounded-lg p-3 flex gap-3 items-start`}
              style={{ backgroundColor: bg, borderLeft: `4px solid ${borderColor}` }}
            >
              <span className={`material-symbols-outlined text-xl shrink-0`} style={{ color: borderColor }}>
                {msg.icon}
              </span>
              <p className="font-sans text-sm text-text leading-relaxed flex-1">{msg.text}</p>
            </div>
          )
        })}
      </div>
    </div>
  )
}
