"use client"

import { useState, useMemo, useEffect } from "react"
import ChatModal from "./ChatModal"

interface ContatosModalProps {
  isOpen: boolean
  onClose: () => void
}

interface Professor {
  id: number
  nome: string
  disciplina: string
  email: string
  ramal: string
  disponibilidade: string
}

interface Setor {
  id: number
  nome: string
  descricao: string
  email: string
  ramal: string
  horario: string
}

const professores: Professor[] = [
  {
    id: 1,
    nome: "Prof. Raphael Cardoso Mota Pereira",
    disciplina: "Interface Homem-Máquina",
    email: "raphael.pereira@inatel.br",
    ramal: "3001",
    disponibilidade: "Seg-Qui 14h-18h",
  },
  {
    id: 2,
    nome: "Prof. Carlos Francisco de Almeida",
    disciplina: "Circuitos Elétricos",
    email: "carlos.almeida@inatel.br",
    ramal: "3002",
    disponibilidade: "Ter-Sex 9h-13h",
  },
  {
    id: 3,
    nome: "Dr. Felipe Emanoel Chaves",
    disciplina: "Álgebra e Geometria, Cálculo III",
    email: "felipe.chaves@inatel.br",
    ramal: "3003",
    disponibilidade: "Seg-Qua 10h-14h",
  },
  {
    id: 4,
    nome: "Prof. Breno Monteiro dos Santos",
    disciplina: "Física II e III",
    email: "breno.santos@inatel.br",
    ramal: "3004",
    disponibilidade: "Qua-Sex 15h-19h",
  },
  {
    id: 5,
    nome: "Prof. Carlos Alberto Ynoguti",
    disciplina: "Algoritmos",
    email: "carlos.ynoguti@inatel.br",
    ramal: "3005",
    disponibilidade: "Ter-Qui 8h-12h",
  },
]

const setores: Setor[] = [
  {
    id: 1,
    nome: "Secretaria Acadêmica",
    descricao: "Documentos, matrículas e histórico",
    email: "secretaria@inatel.br",
    ramal: "2000",
    horario: "Seg-Sex 8h-18h",
  },
  {
    id: 2,
    nome: "Financeiro",
    descricao: "Mensalidades e bolsas",
    email: "financeiro@inatel.br",
    ramal: "2001",
    horario: "Seg-Sex 9h-17h",
  },
  {
    id: 3,
    nome: "Biblioteca",
    descricao: "Empréstimos e renovações",
    email: "biblioteca@inatel.br",
    ramal: "2002",
    horario: "Seg-Sáb 7h-22h",
  },
  {
    id: 4,
    nome: "CTIC",
    descricao: "Problemas técnicos e sistemas",
    email: "ctic@inatel.br",
    ramal: "2003",
    horario: "Seg-Sex 8h-20h",
  },
]

export default function ContatosModal({ isOpen, onClose }: ContatosModalProps) {
  const [activeTab, setActiveTab] = useState<"professores" | "setores">("professores")
  const [searchTerm, setSearchTerm] = useState("")
  const [expandedId, setExpandedId] = useState<number | null>(null)
  const [chatOpen, setChatOpen] = useState(false)
  const [chatContact, setChatContact] = useState({ nome: "", tipo: "" })

  useEffect(() => {
    if (isOpen) {
      document.body.style.overflow = "hidden"
    } else {
      document.body.style.overflow = "auto"
      setSearchTerm("")
      setExpandedId(null)
    }
  }, [isOpen])

  const filteredProfessores = useMemo(() => {
    return professores.filter(
      (p) =>
        p.nome.toLowerCase().includes(searchTerm.toLowerCase()) ||
        p.disciplina.toLowerCase().includes(searchTerm.toLowerCase()),
    )
  }, [searchTerm])

  const filteredSetores = useMemo(() => {
    return setores.filter(
      (s) =>
        s.nome.toLowerCase().includes(searchTerm.toLowerCase()) ||
        s.descricao.toLowerCase().includes(searchTerm.toLowerCase()),
    )
  }, [searchTerm])

  const handleAction = (action: string, nome: string, contact: string) => {
    if (action === "chat") {
      setChatContact({ nome, tipo: activeTab === "professores" ? "Professor(a)" : "Setor" })
      setChatOpen(true)
    } else {
      const messages = {
        email: `Abrindo cliente de email para: ${contact}`,

        ramal: `${activeTab === "professores" ? "Iniciando chamada para o professor" : "Iniciando chamada para o setor"}: ${contact}`,
      }
      alert(messages[action as keyof typeof messages])
    }
  }

  if (!isOpen) return null

  return (
    <>
      {/* Overlay com backdrop blur */}
      <div className="fixed inset-0 bg-black/40 backdrop-blur-md z-50 animate-fadeIn" onClick={onClose} />

      {/* Modal */}
      <div className="fixed inset-0 z-50 flex items-center justify-center p-4 pointer-events-none">
        <div
          className="bg-back2/95 backdrop-blur-xl rounded-2xl shadow-2xl w-full max-w-2xl max-h-[85vh] overflow-hidden pointer-events-auto animate-slideUp"
          onClick={(e) => e.stopPropagation()}
        >
          {/* Header */}
          <div className="bg-linear-to-r from-click/10 to-click/5 px-6 py-5 border-b border-click/20">
            <div className="flex items-center justify-between">
              <div className="flex items-center gap-3">
                <span className="material-symbols-outlined text-click text-3xl">contacts</span>
                <h2 className="text-xl font-bold text-text">Contatos Rápidos</h2>
              </div>
              <button
                onClick={onClose}
                className="text-text/60 hover:text-click transition-colors duration-200"
                aria-label="Fechar"
              >
                <span className="material-symbols-outlined text-3xl">close</span>
              </button>
            </div>
          </div>

          {/* Tabs */}
          <div className="flex border-b border-gray-200">
            <button
              onClick={() => {
                setActiveTab("professores")
                setSearchTerm("")
                setExpandedId(null)
              }}
              className={`flex-1 px-6 py-4 font-sans text-sm font-medium transition-all duration-200 hover:cursor-pointer ${
                activeTab === "professores"
                  ? "text-click border-b-2 border-click bg-click/5"
                  : "text-text/60 hover:text-click hover:bg-click/5"
              }`}
            >
              <span className="material-symbols-outlined text-xl align-middle mr-2">school</span>
              Professores
            </button>
            <button
              onClick={() => {
                setActiveTab("setores")
                setSearchTerm("")
                setExpandedId(null)
              }}
              className={`flex-1 px-6 py-4 font-sans text-sm font-medium transition-all duration-200 hover:cursor-pointer ${
                activeTab === "setores"
                  ? "text-click border-b-2 border-click bg-click/5"
                  : "text-text/60 hover:text-click hover:bg-click/5"
              }`}
            >
              <span className="material-symbols-outlined text-xl align-middle mr-2">domain</span>
              Setores
            </button>
          </div>

          {/* Search Bar */}
          <div className="px-6 py-4 bg-back1/30">
            <div className="relative">
              <span className="material-symbols-outlined absolute left-3 top-1/2 -translate-y-1/2 text-click/60">
                search
              </span>
              <input
                type="text"
                placeholder={`Buscar ${activeTab === "professores" ? "professor" : "setor"}...`}
                value={searchTerm}
                onChange={(e) => setSearchTerm(e.target.value)}
                className="w-full pl-11 pr-4 py-3 bg-back2 border border-click/20 rounded-xl font-sans text-sm text-text placeholder:text-text/40 focus:outline-none focus:ring-2 focus:ring-click/40 transition-all duration-200"
              />
            </div>
          </div>

          {/* Content */}
          <div className="overflow-y-auto max-h-[calc(85vh-240px)] px-6 py-4">
            {activeTab === "professores" ? (
              <div className="space-y-3">
                {filteredProfessores.map((prof) => (
                  <div
                    key={prof.id}
                    className="bg-back2 border border-click/10 rounded-xl overflow-hidden hover:shadow-lg hover:-translate-y-0.5 transition-all duration-300"
                  >
                    <button
                      onClick={() => setExpandedId(expandedId === prof.id ? null : prof.id)}
                      className="w-full px-5 py-4 flex items-center justify-between text-left hover:cursor-pointer"
                    >
                      <div className="flex items-center gap-3 flex-1 min-w-0">
                        <div className="w-10 h-10 rounded-full bg-click/10 flex items-center justify-center shrink-0">
                          <span className="material-symbols-outlined text-click text-xl">person</span>
                        </div>
                        <div className="flex-1 min-w-0">
                          <h3 className="font-sans font-bold text-sm text-text truncate">{prof.nome}</h3>
                          <p className="font-sans text-xs text-text/60 truncate">{prof.disciplina}</p>
                        </div>
                      </div>
                      <span
                        className={`material-symbols-outlined text-click transition-transform duration-300 ${expandedId === prof.id ? "rotate-180" : ""}`}
                      >
                        expand_more
                      </span>
                    </button>

                    {expandedId === prof.id && (
                      <div className="px-5 pb-4 pt-2 bg-linear-to-b from-click/5 to-transparent border-t border-click/10 animate-fadeIn">
                        <div className="space-y-2 mb-4">
                          <div className="flex items-center gap-2 text-xs font-sans text-text/70">
                            <span className="material-symbols-outlined text-base">schedule</span>
                            {prof.disponibilidade}
                          </div>
                          <div className="flex items-center gap-2 text-xs font-sans text-text/70">
                            <span className="material-symbols-outlined text-base">call</span>
                            Ramal: {prof.ramal}
                          </div>
                        </div>
                        <div className="flex gap-2">
                          <button
                            onClick={() => handleAction("email", prof.nome, prof.email)}
                            className="flex-1 px-3 py-2 bg-blue-500 hover:bg-blue-600 text-white rounded-lg font-sans text-xs font-medium transition-colors duration-200 flex items-center justify-center gap-1 hover:cursor-pointer"
                          >
                            <span className="material-symbols-outlined text-base">mail</span>
                            Email
                          </button>
                          <button
                            onClick={() => handleAction("ramal", prof.nome, prof.ramal)}
                            className="flex-1 px-3 py-2 bg-green-500 hover:bg-green-600 text-white rounded-lg font-sans text-xs font-medium transition-colors duration-200 flex items-center justify-center gap-1 hover:cursor-pointer"
                          >
                            <span className="material-symbols-outlined text-base">call</span>
                            Ligar
                          </button>
                          <button
                            onClick={() => handleAction("chat", prof.nome, "")}
                            className="flex-1 px-3 py-2 bg-purple-500 hover:bg-purple-600 text-white rounded-lg font-sans text-xs font-medium transition-colors duration-200 flex items-center justify-center gap-1 hover:cursor-pointer"
                          >
                            <span className="material-symbols-outlined text-base">chat</span>
                            Chat
                          </button>
                        </div>
                      </div>
                    )}
                  </div>
                ))}
                {filteredProfessores.length === 0 && (
                  <div className="text-center py-12">
                    <span className="material-symbols-outlined text-text/20 text-6xl mb-2">search_off</span>
                    <p className="font-sans text-sm text-text/60">Nenhum professor encontrado</p>
                  </div>
                )}
              </div>
            ) : (
              <div className="space-y-3">
                {filteredSetores.map((setor) => (
                  <div
                    key={setor.id}
                    className="bg-back2 border border-click/10 rounded-xl overflow-hidden hover:shadow-lg hover:-translate-y-0.5 transition-all duration-300"
                  >
                    <button
                      onClick={() => setExpandedId(expandedId === setor.id ? null : setor.id)}
                      className="w-full px-5 py-4 flex items-center justify-between text-left hover:cursor-pointer"
                    >
                      <div className="flex items-center gap-3 flex-1 min-w-0">
                        <div className="w-10 h-10 rounded-full bg-click/10 flex items-center justify-center shrink-0">
                          <span className="material-symbols-outlined text-click text-xl">apartment</span>
                        </div>
                        <div className="flex-1 min-w-0">
                          <h3 className="font-sans font-bold text-sm text-text truncate">{setor.nome}</h3>
                          <p className="font-sans text-xs text-text/60 truncate">{setor.descricao}</p>
                        </div>
                      </div>
                      <span
                        className={`material-symbols-outlined text-click transition-transform duration-300 ${expandedId === setor.id ? "rotate-180" : ""}`}
                      >
                        expand_more
                      </span>
                    </button>

                    {expandedId === setor.id && (
                      <div className="px-5 pb-4 pt-2 bg-linear-to-b from-click/5 to-transparent border-t border-click/10 animate-fadeIn">
                        <div className="space-y-2 mb-4">
                          <div className="flex items-center gap-2 text-xs font-sans text-text/70">
                            <span className="material-symbols-outlined text-base">schedule</span>
                            {setor.horario}
                          </div>
                          <div className="flex items-center gap-2 text-xs font-sans text-text/70">
                            <span className="material-symbols-outlined text-base">call</span>
                            Ramal: {setor.ramal}
                          </div>
                        </div>
                        <div className="flex gap-2">
                          <button
                            onClick={() => handleAction("email", setor.nome, setor.email)}
                            className="flex-1 px-3 py-2 bg-blue-500 hover:bg-blue-600 text-white rounded-lg font-sans text-xs font-medium transition-colors duration-200 flex items-center justify-center gap-1 hover:cursor-pointer"
                          >
                            <span className="material-symbols-outlined text-base">mail</span>
                            Email
                          </button>
                          <button
                            onClick={() => handleAction("ramal", setor.nome, setor.ramal)}
                            className="flex-1 px-3 py-2 bg-green-500 hover:bg-green-600 text-white rounded-lg font-sans text-xs font-medium transition-colors duration-200 flex items-center justify-center gap-1 hover:cursor-pointer"
                          >
                            <span className="material-symbols-outlined text-base">call</span>
                            Ligar
                          </button>
                          <button
                            onClick={() => handleAction("chat", setor.nome, "")}
                            className="flex-1 px-3 py-2 bg-purple-500 hover:bg-purple-600 text-white rounded-lg font-sans text-xs font-medium transition-colors duration-200 flex items-center justify-center gap-1 hover:cursor-pointer"
                          >
                            <span className="material-symbols-outlined text-base">chat</span>
                            Chat
                          </button>
                        </div>
                      </div>
                    )}
                  </div>
                ))}
                {filteredSetores.length === 0 && (
                  <div className="text-center py-12">
                    <span className="material-symbols-outlined text-text/20 text-6xl mb-2">search_off</span>
                    <p className="font-sans text-sm text-text/60">Nenhum setor encontrado</p>
                  </div>
                )}
              </div>
            )}
          </div>
        </div>
      </div>

      <ChatModal
        isOpen={chatOpen}
        onClose={() => setChatOpen(false)}
        contactName={chatContact.nome}
        contactType={chatContact.tipo}
      />
    </>
  )
}
