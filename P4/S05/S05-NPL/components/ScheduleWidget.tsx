"use client"
import { useEffect, useState } from "react"
interface Aula {
  id: number
  disciplina: string
  horario: string
  local: string
  professor: string
  prova?: boolean
  dataProva?: string
}

const aulas: Aula[] = [
  {
    id: 1,
    disciplina: "Interface Homem-máquina",
    horario: "10:00 - 12:00",
    local: "I-17",
    professor: "Prof. Raphael Cardoso",
  },
  {
    id: 2,
    disciplina: "Circuitos Elétricos",
    horario: "14:00 - 16:00",
    local: "III-L05",
    professor: "Prof. Carlos Francisco",
    prova: true,
    dataProva: "Amanhã",
  },
  {
    id: 3,
    disciplina: "Álgebra e Geometria Analítica",
    horario: "16:00 - 18:00",
    local: "I-12",
    professor: "Dr. Felipe Chaves",
  },
]

export default function ScheduleWidget() {
  const [isDark, setIsDark] = useState(false)

  useEffect(() => {
    const detect = () => setIsDark(document.documentElement.classList.contains('dark'))
    detect()
    const obs = new MutationObserver(detect)
    obs.observe(document.documentElement, { attributes: true, attributeFilter: ['class'] })
    return () => obs.disconnect()
  }, [])

  const isClientDark = isDark

  return (
    <div className="bg-back2 rounded-2xl shadow-lg p-5 border">
      <h3 className="font-sans font-bold text-lg text-text mb-4 flex items-center gap-2">
        <span className="material-symbols-outlined text-click">calendar_today</span>
        Aulas de Hoje
      </h3>
      <div className="space-y-3">
        {aulas.map((aula) => (
          <div
            key={aula.id}
            className={`border-l-4 ${
              isClientDark ? 'border-gray-600 bg-back1 hover:shadow-md hover:shadow-neutral-100/10' : 'border-click bg-linear-to-r from-blue-50 to-white'
            } rounded-r-xl p-4 hover:shadow-md transition-shadow`}
          >
            <div className="flex items-start justify-between gap-3">
              <div className="flex-1">
                <h4 className="font-sans font-bold text-sm text-text mb-1">{aula.disciplina}</h4>
                <div className="flex flex-wrap gap-x-4 gap-y-1 text-xs text-text/80">
                  <span className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-sm">schedule</span>
                    {aula.horario}
                  </span>
                  <span className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-sm">room</span>
                    {aula.local}
                  </span>
                  <span className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-sm">person</span>
                    {aula.professor}
                  </span>
                </div>
              </div>
              {aula.prova && (
                <div className="bg-red-500 text-white text-xs font-bold px-3 py-1 rounded-full flex items-center gap-1 shrink-0">
                  <span className="material-symbols-outlined text-sm">warning</span>
                  Prova {aula.dataProva}
                </div>
              )}
            </div>
          </div>
        ))}
      </div>
    </div>
  )
}
