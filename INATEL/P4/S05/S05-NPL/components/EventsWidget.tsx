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
  category: string
}

const eventos: Event[] = [
  {
    id: 1,
    title: "Semana do Software 2025",
    date: "12/05",
    time: "10:00",
    location: "Salão de Eventos",
    description: "Uma semana inteira dedicada à tecnologia e inovação com palestras e workshops.",
    image: "https://images.unsplash.com/photo-1504384308090-c894fdcc538d?auto=format&fit=crop&q=80&w=800&h=400",
    category: "Acadêmico",
  },
  {
    id: 2,
    title: "Workshop de IoT",
    date: "12/01",
    time: "08:00",
    location: "Laboratório CS&I",
    description: "Workshop prático sobre Internet das Coisas e aplicações na indústria 4.0.",
    image: "https://images.unsplash.com/photo-1518770660439-4636190af475?auto=format&fit=crop&q=80&w=800&h=400",
    category: "Workshop",
  },
  {
    id: 3,
    title: "Festa dos Alunos 2025",
    date: "18/05",
    time: "19:00",
    location: "Área Esportiva",
    description: "Venha comemorar a melhor Festa dos Alunos de todos os tempos!",
    image: "https://images.unsplash.com/photo-1514525253161-7a46d19cd819?auto=format&fit=crop&q=80&w=800&h=400",
    category: "Social",
  },
]

export default function EventsWidget() {
  const [index, setIndex] = useState(0)
  const [isDark, setIsDark] = useState(false)

  useEffect(() => {
    const interval = setInterval(() => {
      setIndex((prev) => (prev + 1) % eventos.length)
    }, 6000)
    return () => clearInterval(interval)
  }, [])

  useEffect(() => {
    const detect = () => setIsDark(document.documentElement.classList.contains('dark'))
    detect()
    const obs = new MutationObserver(detect)
    obs.observe(document.documentElement, { attributes: true, attributeFilter: ['class'] })
    return () => obs.disconnect()
  }, [])

  const nextCard = () => setIndex((prev) => (prev + 1) % eventos.length)
  const prevCard = () => setIndex((prev) => (prev - 1 + eventos.length) % eventos.length)

  return (
    <div className="bg-back2 rounded-2xl shadow-lg overflow-hidden border">
      <div className="p-5 pb-3">
        <h3 className="font-sans font-bold text-lg text-text flex items-center gap-2">
          <span className="material-symbols-outlined text-click">event</span>
          Próximos Eventos
        </h3>
      </div>

      <div className="relative overflow-hidden">
        <div
          className="flex transition-transform duration-700 ease-in-out"
          style={{ transform: `translateX(-${index * 100}%)` }}
        >
          {eventos.map((event) => (
            <div key={event.id} className="min-w-full">
              <div className="relative">
                <img src={event.image || "/placeholder.svg"} alt={event.title} className="w-full h-56 object-cover" />
                <div className="absolute top-4 right-4 bg-back2 px-3 py-1 rounded-full text-xs font-bold text-click shadow-lg">
                  {event.category}
                </div>
              </div>
              <div className="p-5">
                <h4 className="font-sans font-bold text-base text-text mb-2">{event.title}</h4>
                <p className="font-sans text-sm text-text/80 leading-relaxed mb-3">{event.description}</p>
                <div className="flex flex-wrap gap-3 text-sm text-text/90">
                  <div className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-click text-lg">calendar_today</span>
                    {event.date}
                  </div>
                  <div className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-click text-lg">schedule</span>
                    {event.time}
                  </div>
                  <div className="flex items-center gap-1">
                    <span className="material-symbols-outlined text-click text-lg">pin_drop</span>
                    {event.location}
                  </div>
                </div>
              </div>
            </div>
          ))}
        </div>

        <button
          onClick={prevCard}
          className="absolute left-3 top-1/3 -translate-y-1/2 bg-back2/90 hover:bg-back2 text-click border-none w-10 h-10 cursor-pointer rounded-full shadow-lg hover:shadow-xl transition-all flex items-center justify-center"
          aria-label="Anterior"
        >
          <span className="material-symbols-outlined">chevron_left</span>
        </button>
        <button
          onClick={nextCard}
          className="absolute right-3 top-1/3 -translate-y-1/2 bg-back2/90 hover:bg-back2 text-click border-none w-10 h-10 cursor-pointer rounded-full shadow-lg hover:shadow-xl transition-all flex items-center justify-center"
          aria-label="Próximo"
        >
          <span className="material-symbols-outlined">chevron_right</span>
        </button>
      </div>

      <div className="flex justify-center gap-2 pb-4">
        {eventos.map((_, idx) => (
            <button
            key={idx}
            onClick={() => setIndex(idx)}
            className={`w-2 h-2 rounded-full transition-all ${idx === index ? "bg-click w-6" : (isDark ? "bg-back2/60 hover:bg-back2/70" : "bg-gray-300 hover:bg-gray-400")}`}
            aria-label={`Ir para slide ${idx + 1}`}
          />
        ))}
      </div>
    </div>
  )
}
