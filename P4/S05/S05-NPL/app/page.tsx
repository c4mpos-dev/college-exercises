"use client"

import { useState } from "react"
import Header from "@/components/Header"
import Sidebar from "@/components/Sidebar"
import DashboardGrid from "@/components/DashboardGrid"
import ContatosModal from "@/components/ContatosModal"

export default function Dashboard() {
  const [isSidebarOpen, setIsSidebarOpen] = useState(false)
  const [isContatosOpen, setIsContatosOpen] = useState(false)

  return (
    <div className="min-h-screen bg-back1">
      <Sidebar
        isOpen={isSidebarOpen}
        onClose={() => setIsSidebarOpen(false)}
        onOpenContatos={() => {
          setIsContatosOpen(true)
          setIsSidebarOpen(false)
        }}
      />

      <Header onMenuClick={() => setIsSidebarOpen(true)} />

      <main className="px-5 pb-8 pt-5">
        <DashboardGrid userName="Raphael" />
      </main>

      <ContatosModal isOpen={isContatosOpen} onClose={() => setIsContatosOpen(false)} />
    </div>
  )
}
