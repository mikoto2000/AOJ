use std::str::FromStr;

fn main() {
    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let n: usize = FromStr::from_str(&line1[0]).unwrap();
    let m: usize = FromStr::from_str(&line1[1]).unwrap();

    let mut a = vec![vec![0; m]; n];
    let mut b = vec![vec![0; 1]; m];

    // a の値取得
    for i in 0..n {
        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();
        let line2: Vec<&str> = line2.split_whitespace().collect();

        for j in 0..m {
            a[i][j] = FromStr::from_str(&line2[j]).unwrap();
        }
    }

     // m1 の値取得
    for i in 0..m {
        let mut line3 = String::new();
        std::io::stdin().read_line(&mut line3).ok();
        line3 = line3.trim().parse::<String>().ok().unwrap();
        let line3: Vec<&str> = line3.split_whitespace().collect();
        b[i][0] = FromStr::from_str(&line3[0]).unwrap();
    }

    // a*b の計算
    let mut c = vec![0; n];
    for i in 0..n {
        // c[n] の計算
        for j in 0..m {
            c[i] = c[i] + a[i][j]*b[j][0]
        }
        println!("{}", c[i]);
    }
}
