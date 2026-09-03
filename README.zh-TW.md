[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md)

# 單挑德州撲克博弈 AI 引擎|德州扑克AI |德州AI|基于CFR与深度强化学习的德州扑克AI研究项目


[![Win Rate](https://img.shields.io/badge/AI胜率-顶级职业选手-red)]()

[![Platform](https://img.shields.io/badge/平台-Linux%20%7C%20Windows-green)]()


---


## 🏆 戰績證明 | Proven Results


> **2020年9月22日，MasterAI 在與14位中國頂級職業選手的31561手牌對決中，以每百手贏取36.38大盲的優勢取勝**


| 指標 | 數據 |

| :--- | :--- |

| 對戰手牌數 | 31,561 手 |

| 百手贏利 | +36.38 BB |

| 對手等級 | 14位中國頂尖職業選手 |

| 比賽形式 | 一對一有限押注 (0-100BB) |


---

## 🤖 Texas Holdem Poker AI (1v1 Heads-Up Engine)|(1v9 Heads-Up Engine)


💡 Advanced Poker AI trained with game theory & reinforcement learning

💡 高級德州撲克AI（博弈論 + 強化學習）


🔥 1v1 Heads-Up Poker AI

🔥 Real Decision-Making Engine

🔥 High-Level Strategy Simulation


---


## 🧠 AI Overview | AI說明


### 🇺🇸 English

- Based on game theory (Nash equilibrium)

- Reinforcement learning training

- Decision-making under uncertainty

- Designed for heads-up poker


### 🇨🇳 中文

- 基於賽局理論（納許均衡）

- 強化學習訓練

- 不完全資訊決策

- 適用於1v1德州

## 🧠 核心技術 | Technology


MasterAI 基於**賽局理論(GTO) + 深度學習 + 強化學習**，採用以下前沿技術：


| 技術 | 說明 |

| :--- | :--- |

| **CFR演算法** | 虛擬遺憾最小化，計算納許均衡策略 |

| **蒙特卡羅採樣** | 大量MC採樣逼近最優行動價值 |

| **神經網路估值** | 離線求解+線上連續重解 |

| **納許均衡策略** | GTO最優策略，無法被利用 |


### 架構組成


- **離線組件**：求解隨機撲克局面，訓練神經網路預測每手牌的價值

- **線上元件**：使用連續重解演算法，動態選擇最優行動


---


## 📁 程式碼結構

├── APGIServer/ # API服務

├── CfrServer/ # CFR演算法核心 (遺憾最小化)

├── Common/ # 公用庫

├── Models/ # AI訓練模型

└── Proto/ # 協定定義


**語言佔比**：C++ 81% | C 18% | 其他 1%


---


## 🧠 AI Core/AI說明（核心）


- Reinforcement Learning (Self-play)

- Game Theory (Nash Equilibrium Approximation)

- Monte Carlo Simulation

- Decision-making under uncertainty

## 📊 Performance


- Win rate vs baseline AI: +XX%

- Average decision time: XX ms

- Strategy depth: Advanced


---


### 💰問題回饋與交流

僅限學術與科技交流


📱 **Telegram：@xuzongbin001**

📧 **Email：masterai918@gmail.com**


---


⭐ Star 這個倉庫，謝謝支持


## 📸 實戰截圖

MasterAI賽事狀況如下 ：
![640](https://github.com/user-attachments/assets/8982ce0a-4d9b-4c55-bfb2-ec8228e1a23a)
![640 (1)](https://github.com/user-attachments/assets/4c5591c7-e59a-4fde-8af9-723243ce0cf1)
9/1~9/4 首屆全明星邀請賽，MasterAI 機器人已擊敗頂尖撲克遊戲職業高手每百手贏取大盲達到平均36.38的水準，大贏人類職業選手。
![微信图片_20241030105723](https://github.com/user-attachments/assets/3d473e19-db23-4cf2-a4d2-50d73cb8ab77)
![微信图片_20241030103520](https://github.com/user-attachments/assets/3fd8c2d9-8dde-42a9-a82f-1f8677610735)


![Stars](https://img.shields.io/github/stars/masterai-top/TexasHoldem-Poker-AI-HeadsUp-Engine?style=social)
![Last Commit](https://img.shields.io/github/last-commit/masterai-top/TexasHoldem-Poker-AI-HeadsUp-Engine)
