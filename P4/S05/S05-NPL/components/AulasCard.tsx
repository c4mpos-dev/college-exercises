"use client"

interface Aula {
  id: number
  disciplina: string
  data: string
  horario: string
  local: string
  prova_alert: boolean
  prova: string
  frequencia: string
  nota: string
}

const aulas: Aula[] = [
  {
    id: 1,
    disciplina: "S05 - Interface Homem-máquina",
    data: "ter",
    horario: "10:00",
    local: "P1-S17",
    prova_alert: false,
    prova: "12/05",
    frequencia: "10/25",
    nota: "10",
  },
  {
    id: 2,
    disciplina: "E01 - Circuitos Elétricos em Corrente Contínua",
    data: "ter",
    horario: "10:00",
    local: "P1-S17",
    prova_alert: true,
    prova: "12/05",
    frequencia: "10/25",
    nota: "5",
  },
  {
    id: 3,
    disciplina: "M02 - Álgebra e Geometria Analítica",
    data: "qua",
    horario: "10:00",
    local: "P1-S17",
    prova_alert: true,
    prova: "12/05",
    frequencia: "10/25",
    nota: "7",
  },
]

export default function AulasCard() {
  const hoje = "ter"
  const aulasDia = aulas.filter((a) => a.data === hoje)

  const getNotaColor = (nota: string) => {
    const n = Number(nota)
    if (n < 6) return "bg-red-500"
    if (n < 8) return "bg-orange-500"
    return "bg-green-500"
  }

  return (
    <div className="space-y-4 mt-5">
      {aulasDia.map((aula) => (
        <div key={aula.id} className="bg-back2 rounded-xl shadow-md p-4">
          {aula.prova_alert && (
            <div className="bg-click text-white rounded-full px-4 py-2 inline-block mb-3 font-sans text-[11px] font-medium">
              PROVA: <span className="font-bold">{aula.prova}</span>
            </div>
          )}
          <h3 className="font-sans font-bold text-[15px] text-text mb-1 truncate">{aula.disciplina}</h3>
          <p className="font-sans text-[11px] text-text mb-3 leading-relaxed">
            Local e Horário:{" "}
            <span className="font-bold">
              {aula.local} - {aula.horario}
            </span>
          </p>
          <div className="flex gap-2 flex-wrap">
            <div className="bg-click text-white rounded-full px-4 py-2 font-sans text-[11px]">
              FALTAS: <span className="font-bold">{aula.frequencia}</span>
            </div>
            <div className={`${getNotaColor(aula.nota)} text-white rounded-full px-4 py-2 font-sans text-[11px]`}>
              NOTA: <span className="font-bold">{aula.nota}</span>
            </div>
          </div>
        </div>
      ))}
    </div>
  )
}
