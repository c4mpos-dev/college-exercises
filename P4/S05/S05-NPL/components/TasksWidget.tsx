"use client"

import { useState } from "react"

interface Task {
  id: number
  text: string
  completed: boolean
  priority: "high" | "medium" | "low"
}

export default function TasksWidget() {
  const [tasks, setTasks] = useState<Task[]>([
    { id: 1, text: "Entregar trabalho de IHM", completed: false, priority: "high" },
    { id: 2, text: "Estudar para prova de Circuitos", completed: false, priority: "high" },
    { id: 3, text: "Revisar exercícios de Álgebra", completed: false, priority: "medium" },
    { id: 4, text: "Ler capítulo 5 do livro", completed: true, priority: "low" },
    { id: 5, text: "Participar do workshop de IoT", completed: false, priority: "medium" },
  ])

  const toggleTask = (id: number) => {
    setTasks(tasks.map((task) => (task.id === id ? { ...task, completed: !task.completed } : task)))
  }

  const getPriorityColor = (priority: string) => {
    if (priority === "high") return "border-red-500"
    if (priority === "medium") return "border-orange-500"
    return "border-green-500"
  }

  return (
    <div className="bg-back2 rounded-2xl shadow-lg p-5 border h-full">
      <h3 className="font-sans font-bold text-lg text-text mb-4 flex items-center gap-2">
        <span className="material-symbols-outlined text-click">checklist</span>
        Minhas Tarefas
      </h3>
      <div className="space-y-2 max-h-96 overflow-y-auto">
        {tasks.map((task) => (
          <div
            key={task.id}
            className={`border-l-4 ${getPriorityColor(task.priority)} bg-gray-50 rounded-r-lg p-3 flex items-start gap-3 hover:bg-gray-100 transition-colors cursor-pointer ${
              task.completed ? "opacity-50" : ""
            }`}
            onClick={() => toggleTask(task.id)}
          >
                <div
                  className={`w-5 h-5 rounded border-2 shrink-0 flex items-center justify-center mt-0.5 ${
                    task.completed ? "bg-click border-click" : "border-gray-300"
                  }`}
            >
              {task.completed && <span className="material-symbols-outlined text-white text-sm">check</span>}
            </div>
            <p className={`font-sans text-sm text-text flex-1 ${task.completed ? "line-through" : ""}`}>{task.text}</p>
          </div>
        ))}
      </div>
    </div>
  )
}
