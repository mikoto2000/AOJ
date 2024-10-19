use std::str::FromStr;

fn main() {

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let cards_count: u32 = FromStr::from_str(&line1[0]).unwrap();

    // カードを表す配列を定義
    // 1次元目: 絵柄
    // 0: スペード
    // 1: ハート
    // 3: クラブ
    // 4: ダイヤ
    // 2 次元目 数字
    let mut cards = vec![vec![false;13]; 4];

    // 存在するカードを true でマーク
    for _ in 0..cards_count {
        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();
        let line2: Vec<&str> = line2.split_whitespace().collect();
        let suite: String = (line2[0]).to_string();
        let number: usize = FromStr::from_str(&line2[1]).unwrap();

        match &*suite {
            "S" => cards[0][number-1] = true,
            "H" => cards[1][number-1] = true,
            "C" => cards[2][number-1] = true,
            "D" => cards[3][number-1] = true,
            _ => panic!()
        }
    }

    // カードを表す配列をなめて false のモノを出力する
    for suite in 0..4 {
        for number in 0..13 {
            match suite {
                0 => if !cards[suite][number] { println!("{} {}", "S", number + 1) },
                1 => if !cards[suite][number] { println!("{} {}", "H", number + 1) },
                2 => if !cards[suite][number] { println!("{} {}", "C", number + 1) },
                3 => if !cards[suite][number] { println!("{} {}", "D", number + 1) },
                _ => panic!(),
            }
        }
    }
}

