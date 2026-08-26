"use client"

import { useEffect } from "react"

interface SidebarProps {
  isOpen: boolean
  onClose: () => void
  onOpenContatos: () => void
}

export default function Sidebar({ isOpen, onClose, onOpenContatos }: SidebarProps) {
  useEffect(() => {
    if (isOpen) {
      document.body.style.overflow = "hidden"
    } else {
      document.body.style.overflow = "auto"
    }
  }, [isOpen])

  const applyTheme = (theme: "inatel" | "dark") => {
    const themes = {
      inatel: {
        "--cor-click": "#006FC9",
        "--cor-sombra": "#005099",
        "--cor-text": "black",
        "--cor-back1": "#ffffff",
        "--cor-back2": "#f5f5f5",
      },
      dark: {
        "--cor-click": "#006FC9",
        "--cor-sombra": "#003a63",
        "--cor-text": "#E5E7EB",
        "--cor-back1": "#111827", /* fundo (mais claro) */
        "--cor-back2": "#1F2937", /* componentes (ligeiramente mais claro que o fundo) */
      },
    }

    const colors = themes[theme]
    Object.entries(colors).forEach(([key, value]) => {
      document.documentElement.style.setProperty(key, value)
    })
    // toggle `dark` class so Tailwind's .dark rules also apply
    if (theme === "dark") {
      document.documentElement.classList.add("dark")
    } else {
      document.documentElement.classList.remove("dark")
    }

    onClose()
  }

  return (
    <>
      {isOpen && (
        <div
          className="fixed inset-0 bg-black/50 backdrop-blur-sm z-40 transition-opacity duration-300"
          onClick={onClose}
        />
      )}

      {/* Sidebar */}
      <div
        className={`fixed top-0 left-0 h-full w-72 bg-back2 z-50 shadow-2xl transform transition-transform duration-300 ${
          isOpen ? "translate-x-0" : "-translate-x-full"
        }`}
      >
        <div className="p-6">
          <div className="flex items-center justify-between mb-8">
            <h2 className="text-xl font-bold text-text">Menu</h2>
            <button onClick={onClose} className="text-click transition-all duration-200 hover:cursor-pointer hover:scale-105 mt-2">
              <span className="material-symbols-outlined text-3xl">close</span>
            </button>
          </div>

          <nav className="space-y-2">
            <button
              onClick={onOpenContatos}
              className="w-full flex items-center gap-3 px-4 py-3 rounded-lg text-click hover:bg-back1 transition-all duration-200 hover:cursor-pointer hover:scale-105"
            >
              <span className="material-symbols-outlined">call</span>
              <span className="font-sans text-sm">Contatos / Ramais</span>
            </button>

            <div className="border-t border-gray-200 my-4 pt-4">
              <p className="text-xs font-sans text-text/60 px-4 mb-2">Temas</p>
              <button
                onClick={() => applyTheme("inatel")}
                className="w-full flex items-center gap-3 px-4 py-3 rounded-lg text-click hover:bg-back1 transition-all duration-200 hover:cursor-pointer hover:scale-105"
              >
                <span className="material-symbols-outlined">palette</span>
                <span className="font-sans text-sm">Tema Inatel</span>
              </button>
              <button
                onClick={() => applyTheme("dark")}
                className="w-full flex items-center gap-3 px-4 py-3 rounded-lg text-click hover:bg-back1 transition-all duration-200 hover:cursor-pointer hover:scale-105"
              >
                <span className="material-symbols-outlined">palette</span>
                <span className="font-sans text-sm">Tema Dark</span>
              </button>
            </div>
          </nav>
        </div>
      </div>
    </>
  )
}
