main.c 入出力・ループ
parser.c/h 入力文字列をトークンに分割
evaluator.c/h トークンから計算結果を得る
mathfuncs.c/h　sin,cos,sqrtなどを自作(math.hは作らない)
utils.c/h　汎用関数，エラーハンドリング，文字列処理など

arser.c/.h：字句解析（トークナイザー）
役割：
入力文字列を「トークン」に変換
例：3 + 4 * sin(30) → [3][+][4][*][sin][(][30][)]
typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_FUNC,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    double value;          // 数値トークン用
    char op;               // 演算子トークン用
    char func[10];         // 関数名（例："sin"）
} Token;

evaluator.c/.h：式の評価
役割：
トークン列を評価（逆ポーランド記法に変換→スタックで計算）
Shunting Yard アルゴリズム（by Dijkstra）を使う
構成要素：
Token[] → RPN（逆ポーランド記法） → 数値スタックで計算
演算子の優先順位管理（+ - < * / < 関数）
関数例：
double evaluate(Token* tokens);

mathfuncs.c/.h：関数の実装
役割：
数学関数をラップして使いやすく
double call_func(const char* func_name, double arg);
// 例：call_func("sin", 30.0) → 0.5（ラジアン処理もここで）
sin, cos, tan
sqrt, log, exp, abs など

utils.c/.h：汎用関数
役割：

全体で使い回す小さな関数たち（補助的だけど大事）

例：

c
コードをコピーする
int is_operator(char c);
int precedence(char op); // 演算子の優先順位
int is_func_name(const char* str); // sin, cos の判定
void error(const char* msg); // エラーメッセージ表示
補足アドバイス
最初は「数字 + 四則演算 + 括弧」だけ対応でOK
次に「関数」「定数」対応
エラー処理は後からで大丈夫（「0除算」「不正な入力」など）



-----------------------------------------------------------
◻️プロジェクト仕様書（関数電卓 v0.1）◻️
目的：
キーボードから入力された式（例：3 + 4 * 2）を解析し、計算結果を出力する**関数電卓（Scientific Calculator）**を作成する。

全体の処理フロー（簡略化フローチャート）：
[ユーザー入力] (ex: "3 + 4 * 2")
       ↓
[字句解析 (Tokenizer)] 文字列 → トークン列へ変換
       ↓
[構文解析＋評価 (Evaluator)] トークン列を解析して値を計算
       ↓
[結果出力] (ex: "= 11")

モジュール構成（ファイル分割）
main.c	入出力処理、統括
parser.c/h	式の字句解析（トークン化）
evaluator.c/h	トークン列の評価（四則演算）
Makefile	ビルドルール

各モジュールのアルゴリズム詳細

1. main.c
目的：標準入力から文字列を受け取り、トークン化と評価を呼び出す
処理手順：
1. ユーザーから文字列入力
2. `tokenize()` を呼び出してトークン列に変換
3. `evaluate()` を呼び出して数値結果を得る
4. 結果を表示
5. メモリ解放

2. parser.c / parser.h
目的：文字列を構文解析のためのトークン列に分解する

使用する構造体：
typedef enum {
  TOKEN_NUMBER,    // 数値
  TOKEN_OPERATOR,  // '+', '-', '*', '/'
  TOKEN_END        // 終端
} TokenType;

typedef struct {
  TokenType type;
  double value; // 数値用
  char op;      // 演算子用
} Token;
アルゴリズム（tokenize）：

plaintext
1. 入力文字列を左から走査
2. 数字を見つけたら TOKEN_NUMBER に変換（例: "12.5" → 12.5）
3. '+', '-', '*', '/' を見つけたら TOKEN_OPERATOR に変換
4. 空白は無視
5. 最後に TOKEN_END を追加して終了

3. evaluator.c / evaluator.h
目的：トークン列を解析して数値を計算する（v0.1は左から順に評価）
アルゴリズム（※優先度を無視する簡易版）：
例: トークン列 = 3 + 4 * 2
1. 最初のトークンが TOKEN_NUMBER でなければエラー
2. result ← 最初の数値
3. 以降ループ:
    - TOKEN_OPERATOR を取得（例: '+'）
    - 次の TOKEN_NUMBER を取得（例: 4）
    - result に演算を適用（例: result = result + 4）
    - 次のトークンへ進む
4. TOKEN_END でループ終了
5. result を返す

今後追加される処理（例）
機能	影響するモジュール	補足
括弧 ()	evaluator	優先順位の実装が必要
関数（sin）	parser, evaluator	"sin" などをトークン化
エラー処理	main, parser, evaluator	無効文字・構文のチェック
記憶変数	evaluator	ansなどの状態保持
ファイル入出力	main	式ログの保存など

フローチャート図（文章形式）
main.c
  └─ ユーザー入力文字列
        ↓
  └─ parser.tokenize()
        ↓
  └─ evaluator.evaluate()
        ↓
  └─ 結果をprintfで表示

要点まとめ
トークン化（Tokenizer）が最も重要な第一歩
最初は 「左から順に計算」 でよい（後で優先順位対応）
すべてはトークン列をどう扱うかに集約される

次にやること（四則演算）
parser.c に簡単な "3 + 4" を処理できる tokenize 実装
evaluator.c に左から順に計算する evaluate 実装
main.c で呼び出して動作確認


