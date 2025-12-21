"use client"

import Image from "next/image"

interface HeaderProps {
  onMenuClick: () => void
}

export default function Header({ onMenuClick }: HeaderProps) {
  return (
    <header className="relative h-[55px] flex items-center justify-between px-4 bg-intl-blue">
      <button onClick={onMenuClick} className="p-0 bg-transparent border-none cursor-pointer hover:scale-105 transition-transform duration-200" aria-label="Abrir menu">
        <span className="material-symbols-outlined text-white text-[30px]">menu</span>
      </button>

      <div className="absolute left-1/2 -translate-x-1/2 flex items-center">
        <Image src="/Inatel-Branco.png" alt="Logo" width={100} height={100} />
      </div>
    </header>
  )
}
