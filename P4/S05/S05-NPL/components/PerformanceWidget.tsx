"use client"

interface Disciplina {
  nome: string
  nota: number
  faltas: string
}

const disciplinas: Disciplina[] = [
  { nome: "S05", nota: 10, faltas: "14/25" },
  { nome: "E02", nota: 5, faltas: "12/25" },
  { nome: "M02", nota: 7, faltas: "8/25" },
  { nome: "C03", nota: 9.5, faltas: "5/25" },
]

export default function PerformanceWidget() {
  const getNotaColor = (nota: number) => {
    if (nota < 6) return "text-red-600"
    if (nota < 8) return "text-orange-600"
    return "text-green-600"
  }

  const getNotaBg = (nota: number) => {
    if (nota < 6) return "bg-red-100"
    if (nota < 8) return "bg-orange-100"
    return "bg-green-100"
  }

  return (
    <div className="bg-back2 rounded-2xl shadow-lg p-5 border h-full">
      <h3 className="font-sans font-bold text-lg text-text mb-4 flex items-center gap-2">
        <span className="material-symbols-outlined text-click">trending_up</span>
        Desempenho
      </h3>
      <div className="space-y-3">
        {disciplinas.map((disc, idx) => (
          <div key={idx} className="bg-gray-50 rounded-lg p-3">
            <div className="flex items-center justify-between mb-2">
              <span className="font-sans font-medium text-sm text-text">{disc.nome}</span>
              <span className={`font-sans font-bold text-lg ${getNotaColor(disc.nota)}`}>PV1: {disc.nota}</span>
            </div>
            <div className="flex items-center gap-2">
              <div className="flex-1 bg-gray-200 rounded-full h-2 overflow-hidden">
                <div
                  className={`h-full ${getNotaBg(disc.nota)} transition-all`}
                  style={{ width: `${(disc.nota / 10) * 100}%` }}
                />
              </div>
              <span className="text-xs text-text/80">Faltas: {disc.faltas}</span>
            </div>
          </div>
        ))}
      </div>
    </div>
  )
}
