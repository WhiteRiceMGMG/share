# 🎓 学生名簿管理システム - C練習用仕様書

---

## 📌 概要

複数の学生の情報（名前・年齢・成績など）を**構造体で管理**し、**ポインタ**を使って操作します。  
以下の機能を**関数ごとに分けて実装**し、ソースコードをファイルに分割して整理します。

- データの **追加**
- データの **表示**
- データの **検索**
- データの **削除**

---

## 📁 ファイル構成

| ファイル名       | 役割                             |
|------------------|----------------------------------|
| `main.c`         | メイン関数、ユーザーとのやりとり |
| `student.h`      | 構造体定義、関数プロトタイプ      |
| `student.c`      | 関数の中身の実装                  |
| `Makefile`       | コンパイル設定                    |

---

## 🧱 構造体定義

```c
typedef struct {
    int id;
    char name[50];
    int age;
    float grade;
} Student;
```

---

## 🔧 関数仕様一覧（student.c に実装）

### 🟢 `void add_student(Student* list, int* count, Student s);`

- **目的**：学生を配列に追加する  
- **引数**：
  - `Student* list`：学生配列
  - `int* count`：現在の学生数（ポインタで共有）
  - `Student s`：追加する学生データ
- **返り値**：なし（`count` を書き換える）

---

### 🟢 `void print_all_students(Student* list, int count);`

- **目的**：登録された全学生を表示する  
- **引数**：
  - `Student* list`：学生配列
  - `int count`：学生数
- **返り値**：なし（標準出力に表示）

---

### 🟢 `Student* find_student_by_id(Student* list, int count, int id);`

- **目的**：指定された ID の学生を検索する  
- **引数**：
  - `Student* list`：学生配列
  - `int count`：学生数
  - `int id`：検索対象の ID
- **返り値**：
  - 見つかればその学生のポインタ
  - なければ `NULL`

---

### 🟢 `int delete_student(Student* list, int* count, int id);`

- **目的**：指定された ID の学生を削除し、配列を詰める  
- **引数**：
  - `Student* list`：学生配列
  - `int* count`：現在の学生数（ポインタで共有）
  - `int id`：削除対象の ID
- **返り値**：
  - 削除成功：`1`
  - 削除失敗：`0`（見つからなかった場合）

---

## 🛠️ Makefile の例

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.o student.o
	$(CC) $(CFLAGS) -o main main.o student.o

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f *.o main
```

---

## 🚀 ビルドと実行手順

```bash
$ make     # コンパイル
$ ./main   # 実行
```

---

## 🌟 拡張アイデア（余力があれば）

- ファイルに保存・読み込み（`save/load`）
- 動的メモリ確保（`malloc`の活用）
- 成績順や名前順にソート
- メニューUIの充実（switch文などで選択式に）
- 入力チェックやエラーハンドリングの強化

---

## 📝 メモ

- 最大登録数を定義しておくと良い（例：`#define MAX_STUDENTS 100`）
- `fgets()` で名前を入力するとき、改行文字の除去に注意
- 検索や削除に失敗した場合はメッセージを出すと親切

---
