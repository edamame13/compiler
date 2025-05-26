# 自作コンパイラ：独自プログラミング言語

### 📌 開発言語の概要
本プロジェクトでは、独自の簡易プログラミング言語とそのコンパイラを実装しています。  
以下の特徴を持ちます：

### 🔧 言語仕様
	•	変数宣言：SEISU 変数1, 変数2, ...（整数型のみ）
	•	入力命令：IN(変数)
	•	条件分岐：CON(条件) { 命令文 } ELSE { 命令文 }
	•	繰り返し構文：LOOP(条件) { 命令文 }
	•	出力命令：OUT(式)
	•	代入構文：変数 <- 式

### ⚙ 使用可能な演算子
	•	四則演算：+, -, *, /, %
	•	比較演算子：==, <, >, <=, >=, !=
	•	論理演算子：&&, ||
	•	予約語はすべて 大文字 で記述

### 💡 サンプルコード：ユークリッドの互除法（最大公約数）
独自言語による実装
```
SEISU a, b, c, r
IN(a)
IN(b)
CON(a < b) {
    c <- a
    a <- b
    b <- c
}
r <- a % b
LOOP(r != 0) {
    a <- b
    b <- r
    r <- a % b
}
OUT(b)
```

C言語による同等の実装
```
#include <stdio.h>

int main() {
    int a, b, c, r;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a < b) {
        c = a;
        a = b;
        b = c;
    }
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    printf("%d\n", b);
    return 0;
}
```

### 🔠 字句定義（トークン）
| トークン                     | 返す値 |
|-----------------------------|--------|
| CON                         | 1      |
| ELSE                        | 2      |
| LOOP                        | 3      |
| IN                          | 4      |
| OUT                         | 5      |
| SEISU                       | 6      |
| 識別子 (letter+digit組合せ) | 20     |
| 数値 (digit+)               | 200    |
| (                           | 30     |
| )                           | 31     |
| ,                           | 40     |
| {                           | 41     |
| }                           | 42     |
| <-                          | 50     |
| +                           | 51     |
| -                           | 52     |
| *                           | 53     |
| /                           | 54     |
| %                           | 55     |
| ==                          | 61     |
| <                           | 62     |
| >                           | 63     |
| <=                          | 64     |
| =>                          | 65     |
| !=                          | 66     |


### 🧩 文法定義（BNF形式）
```
<block> ::= <varDec> <statementlist>
<varDec> ::= "SEISU" <idlist>
<idlist> ::= ident | ident "," <idlist>
<statementlist> ::= <statement> <statementlist> | ε
<statement> ::= <IN文> | <CON文> | <LOOP文> | <OUT文> | <expression> | <Assignment文>

<IN文> ::= "IN" "(" ident ")"
<CON文> ::= "CON" "(" <condition> ")" "{" <statementlist> "}" <zyanai>
<zyanai> ::= ε | "ELSE" "{" <statement> "}"
<LOOP文> ::= "LOOP" "(" <condition> ")" "{" <statementlist> "}"
<OUT文> ::= "OUT" "(" <expression> ")"
<Assignment文> ::= ident "<-" <expression>

<condition> ::= <expression> <比較演算子> <expression>
<expression> ::= <term> (( "+" | "-" ) <term>)*
<term> ::= <factor> (( "*" | "/" | "%" ) <factor>)*
<factor> ::= ident | number | "(" <expression> ")"
```

### 🧪 字句解析サンプル（ユークリッドの互除法）
```
SEISU a, b, c, r
=> 6 20 40 20 40 20 40 20

IN(a)
=> 4 30 20 31

r <- a % b
=> 20 50 20 55 20
```

### 🐞 エラーメッセージ仕様
	•	字句エラー：It's an unacceptable name（認められない名前です）
	•	構文エラー：It's undefined grammar（定義されていない文法です）特に「大文字を変数に使えない」などを示すメッセージあり
	•	意味エラー：Type integrity mismatch（型の整合性が不一致です）

### 🧾 記号表の仕様
変数名表
| 名前 | 種類 | 型     | 内部コード |
|------|------|--------|------------|
| a    | real | SEISU  | 100        |
| b    | real | SEISU  | 100        |
| c    | real | SEISU  | 100        |
| r    | real | SEISU  | 100        |

整数値表（例）
| 名前 | 種類 | 内部コード |
|------|------|------------|
| 0    | real | 200        |

### 🚀 今後の拡張予定
	•	構文解析機能の実装
	•	意味解析の追加（型チェックなど）
	•	中間コード生成
	•	C言語への翻訳・コード生成
