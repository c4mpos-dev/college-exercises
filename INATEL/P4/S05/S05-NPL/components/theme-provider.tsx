'use client'

import * as React from 'react'
import {
  ThemeProvider as NextThemesProvider,
  type ThemeProviderProps,
} from 'next-themes'

export function ThemeProvider({ children, ...props }: ThemeProviderProps) {
  React.useEffect(() => {
    try {
      const stored = window.localStorage.getItem('theme')
      if (!stored) {
        const inatel = {
          '--cor-click': '#006FC9',
          '--cor-sombra': '#005099',
          '--cor-text': 'black',
          '--cor-back1': '#ffffff',
          '--cor-back2': '#f5f5f5',
        }
        Object.entries(inatel).forEach(([k, v]) => {
          document.documentElement.style.setProperty(k, v as string)
        })
        document.documentElement.classList.remove('dark')
      }
    } catch (e) {}
  }, [])

  return (
    <NextThemesProvider attribute="class" defaultTheme="inatel" {...props}>
      {children}
    </NextThemesProvider>
  )
}
