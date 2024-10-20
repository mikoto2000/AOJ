fn main() {
    use std::str::FromStr;

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let n: usize = FromStr::from_str(&line1[0]).unwrap();
    let m: usize = FromStr::from_str(&line1[1]).unwrap();
    let l: usize = FromStr::from_str(&line1[2]).unwrap();

    let mut a = vec![vec![0; m]; n];
    let mut b = vec![vec![0; l]; m];

    // 入力を取得
    // a
    for i in 0..n {
        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();
        let line2: Vec<&str> = line2.split_whitespace().collect();

        for j in 0..m {
            a[i][j] = FromStr::from_str(&line2[j]).unwrap();
        }
    }

    // b
    for i in 0..m {
        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();
        let line2: Vec<&str> = line2.split_whitespace().collect();

        for j in 0..l {
            b[i][j] = FromStr::from_str(&line2[j]).unwrap();
        }
    }

    // a * b を計算
    let mut c = vec![vec![0; l]; n];
    for i in 0..n {
        for j in 0..l {
            for k in 0..m {
                c[i][j] = c[i][j] as u64 + a[i][k] as u64 * b[k][j] as u64 ;
            }
        }
    }

    // 結果表示
    for i in 0..n {
        println!(
            "{}",
            c[i].iter()
                .map(|v| v.to_string())
                .collect::<Vec<_>>()
                .join(" ")
        );
    }
}
