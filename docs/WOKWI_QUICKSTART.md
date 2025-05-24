# Wokwi Arduino UNO Quick-Start Guide

> This guide walks new contributors through signing up to Wokwi, creating Arduino UNO projects, running simulations, and adding components. Keep this file in your repository root or `/docs` folder for easy access.

---

## 1. Create a Wokwi Account 🆕

1. Navigate to **[wokwi.com](https://wokwi.com)**
2. Click **Sign Up** and register with your email (or GitHub/Google)
3. _(Optional)_ Join the course classroom using the invitation code provided by your instructor to unlock higher-priority build slots

---

## 2. Start a New UNO Simulation 🛠️

1. From the Wokwi dashboard, select:  
   **Simulate with Wokwi Online → Arduino (Uno, Mega, Nano) → Start from Scratch → Arduino UNO**

2. The workspace opens with two main panes:

   | Pane                   | Purpose                                                        |
   | ---------------------- | -------------------------------------------------------------- |
   | **Right – Simulation** | Drag & drop the UNO and peripherals, create wiring connections |
   | **Left – Code**        | Write C/C++ code or modify the default Arduino sketch          |

---

## 3. Run & Control the Simulation ▶️⏹️

- **Start/Stop Simulation** – Green play button (right pane, top-left)
- **Add Components** – Purple **+** button opens the component library
- **Component Documentation** – Hover over any part and click **?** for pinout diagrams and API documentation

---

## 4. Adding Sensors & Peripherals ➕

1. Click the **+** button and search for components (examples: _LED_, _LCD1602_, _MPU-6050_)
2. Drag the component onto the canvas and wire it to the appropriate UNO pins
3. Use the pop-up documentation (**?** icon) for ready-made helper functions and wiring guides

---

## 5. Saving & Sharing Your Project 💾

- Press **Save** (top-right corner) – Wokwi generates a shareable public URL
- Create a plain-text file named **`wokwi-project.txt`** in your sketch folder containing the project URL

**Example file structure:**

```
exercises/exercise-2/src/exercise2_sketch3/
├── exercise2_sketch3.ino
└── wokwi-project.txt  ← Contains: https://wokwi.com/projects/123456789
```

This approach keeps simulation links discoverable, CI-friendly, and avoids hard-coding URLs in documentation.

---

## 6. Troubleshooting Tips 🩺

| Issue                                  | Solution                                                                                   |
| -------------------------------------- | ------------------------------------------------------------------------------------------ |
| **Slow compilation queue**             | Ensure you're logged in – anonymous jobs have lower priority                               |
| **Serial monitor shows no output**     | Verify `Serial.begin(9600);` is in `setup()` and baud rate matches monitor settings        |
| **I/O pin not responding**             | Check wiring connections; use **Logic Analyzer** in sidebar for real-time signal debugging |
| **404 error when opening shared link** | Make simulation public: click **Share → Public** in Wokwi interface                        |

---

**Happy simulating!**  
For questions or improvements to this guide, please open an issue or submit a pull request.
