# Virtual World (C)

A short project completed during the **first year** of studies for the **Object-Oriented Programming** course.  
A console-based simulator of a two-dimensional, turn-based "virtual world."

This project is a turn-based console game written in C++, where the user observes and controls a simulation of a "virtual world" on a 2D grid.  
Each cell can contain a single organism—either an animal or a plant—represented by an ASCII character.  
The player controls a **Human** character using the arrow keys and can activate a special ability called **"Firestorm"**.

The game engine handles the order of organism actions based on initiative and age, resolves collisions (combat, reproduction, feeding), and supports saving and loading the game state from a file.  
The project uses inheritance: the base class is `Organism`, from which `Animal`, `Plant`, and `Human` are derived.
