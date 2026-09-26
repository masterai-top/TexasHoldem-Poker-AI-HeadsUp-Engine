[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md)

# 德州AI源碼｜CFR演算法德州撲克機器人與單挑AI引擎

MasterAI 是線上 README 展示的德州撲克博弈 AI 專案，研究 CFR、賽局理論、強化學習、自我博弈、蒙特卡羅採樣、神經網路估值及即時決策，面向 1v1 Heads-Up 與專案所述 1v9 場景。

> 僅限學術、演算法與技術研究。對戰成績沿用線上 README 的專案方記錄，應以可重現評測獨立核驗。

## 專題導覽

- [德州AI源碼](https://masterai-top.github.io/TexasHoldem-Poker-AI-HeadsUp-Engine/zh-tw/texas-holdem-ai-source-code.html)
- [CFR演算法與德州撲克AI](https://masterai-top.github.io/TexasHoldem-Poker-AI-HeadsUp-Engine/zh-tw/cfr-poker-ai.html)
- [德州機器人與即時決策引擎](https://masterai-top.github.io/TexasHoldem-Poker-AI-HeadsUp-Engine/zh-tw/poker-bot-engine.html)

## 線上 README 原有內容

專案方記錄：2020-09-22 與 14 位中國頂尖職業選手進行 31,561 手牌的一對一對戰，結果為 +36.38 BB/100。核心模組包含 `CfrServer`、`APGIServer`、`Common/SBotInterface`、訓練器、手牌評估、動作樹與 Redis 介面。

## 核心技術

- CFR 反事實遺憾最小化與納許均衡近似
- 蒙特卡羅採樣、神經網路估值與連續重解
- 強化學習、自我博弈、牌力評估與規則過濾
- C/C++ 即時決策服務、房間邏輯及逾時處理

## 實戰截圖

![MasterAI 德州撲克AI賽事截圖 1](https://github.com/user-attachments/assets/8982ce0a-4d9b-4c55-bfb2-ec8228e1a23a)
![MasterAI 德州機器人賽事截圖 2](https://github.com/user-attachments/assets/4c5591c7-e59a-4fde-8af9-723243ce0cf1)
![CFR 德州撲克AI對戰截圖 3](https://github.com/user-attachments/assets/3d473e19-db23-4cf2-a4d2-50d73cb8ab77)
![德州AI源碼對戰截圖 4](https://github.com/user-attachments/assets/3fd8c2d9-8dde-42a9-a82f-1f8677610735)

Telegram：[@xuzongbin001](https://t.me/xuzongbin001) · Email：masterai918@gmail.com
