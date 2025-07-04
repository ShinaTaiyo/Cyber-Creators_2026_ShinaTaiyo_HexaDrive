//===============================================
//
// Title ：AcrobaticGuns
// Author：ShinaTaiyo
//
//===============================================

◆このゲームについて
TPSワイヤーアクションゲームです。フィールドを飛び回り敵を駆逐しましょう！射撃攻撃を当てるとダイブ攻撃可能回数が増えていきます。ダイブ攻撃は強力な範囲攻撃です。ダイブ攻撃中はスロー状態になります。
この法則を活かし、連続でダイブ攻撃を当てると爽快です！実装にあたり条件分岐が多用だったのでステートパターンやストラテジーパターン、コンポジットパターンなどのデザインパターンに挑戦しました。

◆起動方法
・・・
exeファイルをダブルクリック


◆基本操作

=== コントローラー ===
A：ジャンプ
X：モード切替（射撃モードとダイブモードを切り替えます）
Y：後ろを向く
右スティック：移動
左スティック：視点移動
Rトリガー：（射撃モードなら→射撃、ダイブモードなら→ダイブ）
Lトリガー：ダッシュ
ダイブ時にダイブボタンを押しながら壁や床に衝突：建物に引っ付く
BACKSPACE：ポーズ画面を開く
感度調整：ポーズ画面でCAMERASENSITIVITYを選択
引っ付き状態でBボタン：引っ付き射撃モードに変更or戻す
STARTボタン：画面遷移

=== キーボード ===
SPACE:ジャンプ
右クリック：モード切替（射撃モードとダイブモードを切り替えます）
LCONTROL：後ろを向く
WASD：移動
マウスを動かす：視点移動
ダイブ時にダイブボタンを押しながら壁や床に衝突：建物に引っ付く
感度調整：ポーズ画面でCAMERASENSITIVITYを選択
左クリック：射撃・ダイブ
LSHIFT：ダッシュ
引っ付き状態でマウスのミドルボタン：引っ付き射撃モードに変更or戻す
ENTER：画面遷移


◆実装内容
・通常敵を３体実装（射撃に弱い敵、ダイブに弱い敵、何もしない敵）。
・一度置いたオブジェクトを再度自由に値を変えることができるエディタを実装。
・ゲームの大まかな流れを実装。
・射撃に弱い敵が壁を越えてくるように変更。ダイブに弱い敵の射撃角度を大幅調整。何もしない敵の移動速度を激減。
・フェーズマネージャー実装。
・モーションクラス実装。
・ワイヤー実装。
・ダイブやカメラの角度調整を実装。
・モード切替演出を実装。
・引っ付き射撃モードを実装。
・ポーズ画面を実装。
・カメラの感度調整を実装。
・ダイブ攻撃時スロー状態を実装。

◆これから取り組む内容
・ステージギミックを実装。
・ダッシュやダイブ、射撃などのアクションを楽しく使えるステージを作る。
・上記のアクションを上手くいかせるボス戦の実装。
・一つずつ操作を確認するチュートリアルの実装。
・弱点表示の実装
・爆発攻撃の演出を派手に
・ステージによってダイブ攻撃発動条件を変えれるようにする（ダイブ攻撃はこのゲームの醍醐味なので最初のステージでは無制限に使えるようにし、気持ちよさを伝え、後のステージで徐々に条件をきつくし、攻略していく楽しさを伝えようと考えています）
・見た目が小さい敵は爆発を当てた時に吹っ飛ぶようにします。（爽快感の向上）
・カメラ感度調整のモードを追加します。（徐々に旋回速度を上げる等）
・ステージ選択の実装。
・ダイブ攻撃を当てた時に飛び上がるようにし、次に狙うべき場所を考えやすくする。
・ダイブ攻撃を連続で当てた時に連撃コンボを実装。
・エディタをテキストファイルからJSONファイルに変更。
・エディタのデータ編集をImguiに変更（キーボードが圧縮されているので）

◆頑張ったところ
・ワイヤーの表現方法（外積などを上手く活用）
・フィールドを飛び回ることで攻撃を当てやすくなるような射撃タイプの敵の行動制御
・様々な処理の条件分岐にデザインパターンを適用し可読性、効率性の上昇
・座標変換やレイの当たり判定などの理解
・オブジェクトごとに違うデータを編集できるように多態性を利用したエディタ編集

◆改善点
・コーディングルールを最近まで適用していなく、if文の上にコメントが書いてたり、中にコメントが書いていたり、変数宣言時のコメントが揃ってたり揃ってなかったりなど、かなり見づらいです。クラスメイトに添削してもらった後、直している途中です。
・シーンに依存する処理で、シーンが「ゲーム」だったら、「エディット」だったらなどといった分岐が至る箇所にあります。クラスメイトと確認した時に、やはり、GamePlayer、EditPlayerなどといったクラスを作った方が見やすくなることに気づきました。後々直していきます。
・billboardやObjectX、Object2Dなどといったオブジェクト系クラスに、変数を持たせすぎです。例えば、「加速させる」、「点滅させる」、「ホーミングさせる」などといった処理は、継承したオブジェクト全てが行うわけではないです。なので、それらの情報をまとめたクラスを個別に作り、必要なオブジェクトにだけ持たせるなどといった処理を行った方が見やすくなることに気づきました。後々直していきます。


◆開発期間
・・・
２０２４年１０月～２０２４年１２月（後ブラッシュアップ）

◆開発環境
・・・
VisualStudio2019
DirectX9

◆注意事項
・・・
ダイブを発動した時、ダイブ発動ボタンを長押しするかしないかで引っ付き状態、又は攻撃状態に移行します。

◆更新履歴
2025年6月16日　ver1.01公開
