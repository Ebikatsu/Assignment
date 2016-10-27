#!/bin/sh
                               #$ ./cprogram.sh (ソースファイル名) (a.outに渡す引数) で実行します。
if [ $# -ge 1 ] ; then         #引数が一つ以上の場合
    emacs -nw $1               #emacsを開きソースファイルを編集します。
                               #C-x C-sでソースファイルを保存し、C-x C-cでemacsを終了します。
    gcc -Wall $1 2> error.txt  #編集終了後、gccを実行し、gccの標準エラー出力をerror.txtに出力します。
    if [ -s error.txt ] ; then #error.txtのサイズが0でない場合
	cat error.txt          #error.txtの内容を表示します。
	cp /dev/null error.txt #error.txtを空の状態に戻します。
    else                       #error.txtのサイズが0の場合
	shift                  #引数の番号をずらします。(a.outにソースファイル名が渡されないようにする。)
	./a.out $*             #a.outを引数を渡して実行します。
    fi
else
    echo "ソースファイル名を指定して下さい。"
fi
