import yfinance as yf
import matplotlib.pyplot as plt

# 株価データを取得（例：トヨタ）
ticker = yf.Ticker("7203.T")  # 東京証券取引所は「.T」付き
hist = ticker.history(period="1mo")  # 1ヶ月分

# 終値を描画
hist['Close'].plot(title="トヨタ自動車（7203.T）の株価")
plt.xlabel("日付")
plt.ylabel("終値（円）")
plt.grid()
plt.show()

