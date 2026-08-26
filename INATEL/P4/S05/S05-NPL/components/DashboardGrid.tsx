"use client"
import WelcomeWidget from "./WelcomeWidget"
import QuickStatsWidget from "./QuickStatsWidget"
import ScheduleWidget from "./ScheduleWidget"
import TasksWidget from "./TasksWidget"
import EventsWidget from "./EventsWidget"
import PerformanceWidget from "./PerformanceWidget"

interface DashboardGridProps {
  userName: string
}

export default function DashboardGrid({ userName }: DashboardGridProps) {
  return (
    <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-5 auto-rows-min">
      {/* Cartão de boas-vindas */}
      <div className="col-span-2 lg:col-span-3">
        <WelcomeWidget userName={userName} />
      </div>

      {/* Estatísticas rápidas */}
      <div className="col-span-2">
        <QuickStatsWidget />
      </div>

      {/* Tarefas */}
      <div className="col-span-2 lg:col-span-1 lg:row-span-2">
        <TasksWidget />
      </div>

      {/* Agenda */}
      <div className="col-span-2">
        <ScheduleWidget />
      </div>

      {/* Desempenho */}
      <div className="col-span-2 md:col-span-1">
        <PerformanceWidget />
      </div>

      {/* Eventos */}
      <div className="col-span-2 md:col-span-1 lg:col-span-1">
        <EventsWidget />
      </div>
    </div>
  )
}
