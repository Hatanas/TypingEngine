# Typing Engine

タイピングゲームにおけるローマ字入力の判定を行うためのC++ライブラリです。

ローマ字入力では、一つの文字に対して複数の入力方法が存在する場合があります。(例: ひらがなの「し」には、si、shi、ciの3通りある)
これを考慮したローマ字入力判定プログラムを作成することは非常に面倒ですが、このTyping Engineライブラリを使用することでその判定処理をライブラリに任せることができます。

以下は動作デモです。UI部分はOpenSiv3Dを使用しています。

## 機能内容

- かな → ローマ字変換
- 入力文字の正誤判定

Microsoft IMEやGoogle IMEで入力可能なローマ字に対応しています。
以下は対応表です。

|                         |                              |        ローマ字対応表         |                              |                         |
| :---------------------: | :--------------------------: | :---------------------------: | :--------------------------: | :---------------------: |
|         あ<br>a         |         い<br>i / yi         |      う<br>u / wu / whu       |           え<br>e            |         お<br>o         |
|                         |                              |                               |          いぇ<br>ye          |                         |
|       うぁ<br>wha       |       うぃ<br>wi / whi       |                               |       うぇ<br>we / whe       |       うぉ<br>who       |
|      か<br>ka / ca      |           き<br>ki           |      く<br>ku / cu / qu       |           け<br>ke           |      こ<br>ko / co      |
|       きゃ<br>kya       |         きぃ<br>kyi          |          きゅ<br>kyu          |         きぇ<br>kye          |       きょ<br>kyo       |
| くぁ<br>qa / kwa / qwa  | くぃ<br>qi / kwi / qwi / qyi |       くぅ<br>kwu / qwu       | くぇ<br>qe / kwe / qwe /qye  | くぉ<br>qo / kwo / qwo  |
|       くゃ<br>qya       |                              |          くゅ<br>qyu          |                              |       くょ<br>qyo       |
|        さ<br>sa         |     し<br>si / shi / ci      |           す<br>su            |        せ<br>se / ce         |        そ<br>so         |
|    しゃ<br>sya / sha    |         しぃ<br>syi          |       しゅ<br>syu / shu       |      しぇ<br>sye / she       |    しょ<br>syo / sho    |
|       すぁ<br>swa       |         すぃ<br>swi          |          すぅ<br>swu          |         すぇ<br>swe          |       すぉ<br>swo       |
|        た<br>ta         |        ち<br>ti / chi        |        つ<br> tu / tsu        |           て<br>te           |        と<br>to         |
| ちゃ<br>tya / cha / cya |      ちぃ<br>tyi / cyi       |    ちゅ<br>tyu / chu / cyu    |   ちぇ<br>tye / che / cye    | ちょ<br>tyo / cho / cyo |
|       つぁ<br>tsa       |         つぃ<br>tsi          |                               |         つぇ<br>tse          |       つぉ<br>tso       |
|       てゃ<br>tha       |      てぃ<br>thi / t'i       |      てゅ<br>thu / t'yu       |         てぇ<br>the          |       てょ<br>tho       |
|       とぁ<br>twa       |         とぃ<br>twi          |       とぅ<br>twu / t'u       |         とぇ<br>twe          |       とぉ<br>two       |
|        な<br>na         |           に<br>ni           |           ぬ<br>nu            |           ね<br>ne           |        の<br>no         |
|       にゃ<br>nya       |         にぃ<br>nyi          |          にゅ<br>nyu          |         にぇ<br>nye          |       にょ<br>nyo       |
|        は<br>ha         |           ひ<br>hi           |         ふ<br>hu / fu         |           へ<br>he           |        ほ<br>ho         |
|       ひゃ<br>hya       |         ひぃ<br>hyi          |          ひゅ<br>hyu          |         ひぇ<br>hye          |       ひょ<br>hyo       |
| ふぁ<br>fa / hwa / fwa  | ふぃ<br>fi / hwi / fwi / fyi |          ふぅ<br>fwu          | ふぇ<br>fe / hwe / fwe / fye | ふぉ<br>fo / hwo / fwo  |
|       ふゃ<br>fya       |                              |      ふゅ<br>fyu / hwyu       |                              |       ふょ<br>fyo       |
|        ま<br>ma         |           み<br>mi           |           む<br>mu            |           め<br>me           |        も<br>mo         |
|       みゃ<br>mya       |         みぃ<br>myi          |          みゅ<br>myu          |         みぇ<br>mye          |       みょ<br>myo       |
|        や<br>ya         |                              |           ゆ<br>yu            |                              |        よ<br>yo         |
|        ら<br>ra         |           り<br>ri           |           る<br>ru            |           れ<br>re           |        ろ<br>ro         |
|       りゃ<br>rya       |         りぃ<br>ryi          |          りゅ<br>ryu          |         りぇ<br>rye          |       りょ<br>ryo       |
|        わ<br>wa         |          ゐ<br>wyi           |                               |          ゑ<br>wye           |        を<br>wo         |
|   ん<br>nn / xn / n'    |                              |                               |                              |                         |
|      ぁ<br>xa / la      |  ぃ<br>xi / xyi / li / lyi   |         ぅ<br>xu / lu         |  ぇ<br>xe / xye / le / lye   |      ぉ<br>xo / lo      |
|       ゔぁ<br>va        |       ゔぃ<br>vi / vyi       |           ゔ<br>vu            |       ゔぇ<br>ve / vye       |       ゔぉ<br>vo        |
|       ゔゃ<br>vya       |                              |          ゔゅ<br>vyu          |                              |       ゔょ<br>vyo       |
|        が<br>ga         |           ぎ<br>gi           |           ぐ<br>gu            |           げ<br>ge           |        ご<br>go         |
|       ぎゃ<br>gya       |         ぎぃ<br>gyi          |          ぎゅ<br>gyu          |         ぎぇ<br>gye          |       ぎょ<br>gyo       |
|       ぐぁ<br>gwa       |         ぐぃ<br>gwi          |          ぐぅ<br>gwu          |         ぐぇ<br>gwe          |       ぐぉ<br>gwo       |
|        ざ<br>za         |        じ<br>zi / ji         |           ず<br>zu            |           ぜ<br>ze           |        ぞ<br>zo         |
| じゃ<br>zya / ja / jya  |      じぃ<br>zyi / jyi       |    じゅ<br>zyu / ju / jyu     |    じぇ<br>zye / je / jye    | じょ<br>zyo / jo / jyo  |
|       ずぁ<br>zwa       |         ずぃ<br>zwi          |          ずぅ<br>zwu          |         ずぇ<br>zwe          |       ずぉ<br>zwo       |
|        だ<br>da         |           ぢ<br>di           |           づ<br>du            |           で<br>de           |        ど<br>do         |
|                         |                              | っ<br>xtu / xtsu / ltu / ltsu |                              |                         |
|       ぢゃ<br>dya       |         ぢぃ<br>dyi          |          ぢゅ<br>dyu          |         ぢぇ<br>dye          |       ぢょ<br>dyo       |
|       でゃ<br>dha       |      でぃ<br>dhi / d'i       |      でゅ<br>dhu / d'yu       |         でぇ<br>dhe          |       でょ<br>dho       |
|       どぁ<br>dwa       |         どぃ<br>dwi          |       どぅ<br>dwu / d'u       |         どぇ<br>dwe          |       どぉ<br>dwo       |
|        ば<br>ba         |           び<br>bi           |           ぶ<br>bu            |           ぶ<br>be           |        ぼ<br>bo         |
|       びゃ<br>bya       |         びぃ<br>byi          |          びゅ<br>byu          |         びぇ<br>bye          |       びょ<br>byo       |
|        ば<br>pa         |           ぴ<br>pi           |           ぶ<br>pu            |           ぶ<br>pe           |        ぼ<br>po         |
|       ぴゃ<br>pya       |         ぴぃ<br>pyi          |          ぴゅ<br>pyu          |         ぴぇ<br>pye          |       ぴょ<br>pyo       |
|     ゃ<br>xya / lya     |                              |        ゅ<br>xyu / lyu        |                              |     ょ<br>xyo / lyo     |
|     ゎ<br>xwa / lwa     |                              |                               |                              |                         |

- 促音「っ」については、次の文字の子音を重ねる入力にも対応 (あっち → atti など)
  - ただし、2個以上連続した促音には未対応
- 撥音「ん」の入力の一つ「nn」について、2つ目のnを省略した入力にも対応 (てんき → tennki or tenki どちらもOK)
  - 一般的なIMEと同じく、「ん」が最後の文字である場合や、次の文字が母音・な行・や行のときは省略不可

