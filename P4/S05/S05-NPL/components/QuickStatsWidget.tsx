"use client"

import { useEffect, useState } from "react"

interface Stat {
  label: string
  value: string
  icon: string
  color: string
  bgColor: string
}

const stats: Stat[] = [
  { label: "Frequência Média", value: "92%", icon: "check_circle", color: "text-green-600", bgColor: "bg-green-100" },
  { label: "Nota Média", value: "8.5", icon: "school", color: "text-blue-600", bgColor: "bg-blue-100" },
  { label: "Disciplinas Ativas", value: "6", icon: "book", color: "text-purple-600", bgColor: "bg-purple-100" },
  { label: "Próximas Provas", value: "2", icon: "assignment", color: "text-orange-600", bgColor: "bg-orange-100" },
]

export default function QuickStatsWidget() {
  const [isDark, setIsDark] = useState(false)

  useEffect(() => {
    setIsDark(typeof window !== "undefined" && document.documentElement.classList.contains("dark"))
    const obs = new MutationObserver(() => {
      setIsDark(document.documentElement.classList.contains("dark"))
    })
    obs.observe(document.documentElement, { attributes: true, attributeFilter: ["class"] })
    return () => obs.disconnect()
  }, [])

  return (
    <div className="bg-back2 rounded-2xl shadow-lg p-5 border">
      <h3 className="font-sans font-bold text-lg text-text mb-4 flex items-center gap-2">
        <span className="material-symbols-outlined text-click">analytics</span>
        Estatísticas Rápidas
      </h3>
      <div className="grid grid-cols-2 md:grid-cols-4 gap-4">
        {stats.map((stat, idx) => {
          const iconClass = isDark ? "text-text" : stat.color
          const bgClass = isDark ? "bg-back1" : stat.bgColor
          return (
            <div key={idx} className="text-center">
              <div className={`${bgClass} w-14 h-14 rounded-full flex items-center justify-center mx-auto mb-2`}>
                <span className={`material-symbols-outlined ${iconClass} text-2xl`}>{stat.icon}</span>
              </div>
              <div className="font-sans font-bold text-2xl text-text">{stat.value}</div>
              <div className="font-sans text-xs text-text/60 mt-1">{stat.label}</div>
            </div>
          )
        })}
      </div>
    </div>
  )
}
