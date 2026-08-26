"use client"

import { useState, useEffect } from "react"

interface Event {
  id: number
  title: string
  date: string
  time: string
  location: string
  description: string
  image: string
}

const eventos: Event[] = [
  {
    id: 1,
    title: "Semana do Software 2025",
    date: "12/05",
    time: "10:00",
    location: "Salão de Eventos",
    description: "Uma semana inteira dedicada à tecnologia e inovação, com palestras, workshops e hackathons.",
    image: "https://images.unsplash.com/photo-1504384308090-c894fdcc538d?auto=format&fit=crop&q=80&w=800&h=400",
  },
  {
    id: 2,
    title: "Workshop de IoT",
    date: "12/01",
    time: "08:00",
    location: "Laboratório CS&I",
    description: "Workshop prático sobre Internet das Coisas e suas aplicações na indústria 4.0.",
    image: "https://images.unsplash.com/photo-1518770660439-4636190af475?auto=format&fit=crop&q=80&w=800&h=400",
  },
  {
    id: 3,
    title: "Festa dos Alunos 2025",
    date: "18/05",
    time: "19:00",
    location: "Área Esportiva",
    description: "Venha comemorar a melhor Festa dos Alunos de todos os tempos!",
    image: "https://images.unsplash.com/photo-1514525253161-7a46d19cd819?auto=format&fit=crop&q=80&w=800&h=400",
  },
  {
    id: 4,
    title: "Feira de Oportunidades",
    date: "04/05",
    time: "10:00",
    location: "Salão de Eventos",
    description: "Venha conhecer empresas e projetos com destaque na área da engenharia.",
    image: "https://images.unsplash.com/photo-1517245386807-bb43f82c33c4?auto=format&fit=crop&q=80&w=800&h=400",
  },
]

export default function EventsCarousel() {
  const [index, setIndex] = useState(0)

  useEffect(() => {
    const interval = setInterval(() => {
      setIndex((prev) => (prev + 1) % eventos.length)
    }, 5000)
    return () => clearInterval(interval)
  }, [])

  const nextCard = () => setIndex((prev) => (prev + 1) % eventos.length)
  const prevCard = () => setIndex((prev) => (prev - 1 + eventos.length) % eventos.length)

  return (
    <div className="relative bg-back2 rounded-xl shadow-md overflow-hidden mt-5">
      <div className="overflow-hidden">
        <div
          className="flex transition-transform duration-500 ease-in-out"
          style={{ transform: `translateX(-${index * 100}%)` }}
        >
          {eventos.map((event) => (
            <div key={event.id} className="min-w-full">
              <img src={event.image || "/placeholder.svg"} alt={event.title} className="w-full h-48 object-cover" />
              <div className="p-4">
                <h3 className="font-sans font-bold text-sm text-text mb-2">{event.title}</h3>
                <p className="font-sans text-[11px] text-text leading-relaxed mb-2">{event.description}</p>
                <div className="flex items-center gap-3 font-sans text-[11px] text-text">
                  <div className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-click text-base">event</span>
                    {event.date} às {event.time}
                  </div>
                  <div className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-click text-base">pin_drop</span>
                    {event.location}
                  </div>
                </div>
              </div>
            </div>
          ))}
        </div>
      </div>

      <button
        onClick={prevCard}
        className="absolute left-2 top-1/3 -translate-y-1/2 bg-black/50 text-white border-none px-3 py-2 cursor-pointer text-xs rounded hover:bg-black/70 transition-colors"
        aria-label="Anterior"
      >
        ❮
      </button>
      <button
        onClick={nextCard}
        className="absolute right-2 top-1/3 -translate-y-1/2 bg-black/50 text-white border-none px-3 py-2 cursor-pointer text-xs rounded hover:bg-black/70 transition-colors"
        aria-label="Próximo"
      >
        ❯
      </button>
    </div>
  )
}
