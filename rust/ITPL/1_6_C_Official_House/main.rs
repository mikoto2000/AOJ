use std::str::FromStr;

fn main() {
    // 当の入居差情報を表す配列を定義
    let mut house = vec![vec![vec![0; 10] /* 0 人ずつ10 部屋*/; 3] /* 3 階 */; 4] /* 4 棟*/;

    // 情報数取得
    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let ope_num: u32 = FromStr::from_str(&line1[0]).unwrap();

    // ひとつずつ情報を反映していく
    for _ in 0..ope_num {

        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();
        let line2: Vec<&str> = line2.split_whitespace().collect();
        let b: usize = FromStr::from_str(&line2[0]).unwrap();
        let f: usize = FromStr::from_str(&line2[1]).unwrap();
        let r: usize = FromStr::from_str(&line2[2]).unwrap();
        let v: i32 = FromStr::from_str(&line2[3]).unwrap();

        house[b-1][f-1][r-1] = house[b-1][f-1][r-1] + v;
    }

    // 情報出力
    for i in 0..4 { // 4 棟
        for j in 0..3 { // 3 階
            for k in 0..10 { // 10 部屋
                print!(" {}", house[i][j][k]);
            }
            println!();
        }
        if i != 3 {
            println!("####################");
        }
    }
}
