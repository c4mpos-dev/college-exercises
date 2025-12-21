"use client"

interface Message {
  icon: string
  text: string
}

interface MessagesCardProps {
  userName: string
}

const messages: Message[] = [
  { icon: "notifications_active", text: "Você possui um armário reservado com entrega para hoje..." },
  { icon: "mail", text: "Você possui uma pendência no financeiro..." },
]

export default function MessagesCard({ userName }: MessagesCardProps) {
  return (
    <div className="bg-back2 rounded-xl shadow-md p-4 mt-5">
      <div className="font-sans font-bold text-[17px] text-text mb-2">Olá {userName}!</div>
      <div className="space-y-2">
        {messages.map((msg, idx) => (
          <div key={idx} className="flex gap-2">
            <span className="material-symbols-outlined text-click text-lg mt-1 shrink-0">{msg.icon}</span>
            <p className="font-sans text-[11px] text-text leading-relaxed flex-1">{msg.text}</p>
          </div>
        ))}
      </div>
    </div>
  )
}
