fn main() {
    loop {
        use std::str::FromStr;

        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let m: i32 = FromStr::from_str(&line1[0]).unwrap();
        let f: i32 = FromStr::from_str(&line1[1]).unwrap();
        let r: i32 = FromStr::from_str(&line1[2]).unwrap();

        if m == -1 && f == -1 && r == -1 {
            break;
        }

        // グレードの計算

        // 中間試験、期末試験のいずれかを欠席した場合成績は F。
        if m == -1 || f == -1 {
            println!("F");
            continue;
        }

        // 中間試験と期末試験の合計点数が 80 以上ならば成績は A 。
        if m + f >= 80 {
            println!("A");
            continue;
        }

        // 中間試験と期末試験の合計点数が 65 以上 80 未満ならば成績は B。
        if m + f >= 65 {
            println!("B");
            continue;
        }

        // 中間試験と期末試験の合計点数が 50 以上 65 未満ならば成績は C。
        if m + f >= 50 {
            println!("C");
            continue;
        }

        // 中間試験と期末試験の合計点数が 30 以上 50 未満ならば成績は D。 ただし、再試験の点数が 50 以上ならば成績は C。
        if m + f >= 30 {
            if r >= 50 {
                println!("C");
                continue;
            }
            println!("D");
            continue;
        }

        println!("F");
    }
}

