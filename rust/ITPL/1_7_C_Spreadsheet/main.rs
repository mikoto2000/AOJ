fn main() {
    use std::str::FromStr;

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let r: usize = FromStr::from_str(&line1[0]).unwrap();
    let c: usize = FromStr::from_str(&line1[1]).unwrap();

    // 表を入れる 2 次元 vec の作成
    let mut sp = vec![vec![0; c + 1]; r + 1];

    // 行の繰り返し
    for rv in 0..r {
        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();
        let line2: Vec<&str> = line2.split_whitespace().collect();

        // 列を繰り返しながら合計も産出
        for cv in 0..c {
            sp[rv][cv] = FromStr::from_str(&line2[cv]).unwrap();
            sp[rv][c] = sp[rv][c] + sp[rv][cv];
            sp[r][cv] = sp[r][cv] + sp[rv][cv];
            sp[r][c] = sp[r][c] + sp[rv][cv];
        }
    }

    // 情報表示
    for i in 0..r + 1 {
        println!(
            "{}",
            sp[i]
                .iter()
                .map(|v| v.to_string())
                .collect::<Vec<_>>()
                .join(" ")
        );
    }
}
