fn main() {
    use std::str::FromStr;

    loop {
        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let h: u32 = FromStr::from_str(&line1[0]).unwrap();
        let w: u32 = FromStr::from_str(&line1[1]).unwrap();

        if h == 0 && w == 0 {
            break
        }

        // 上枠
        for _ in 0..w {
            print!("#");
        }
        println!();

        for _ in 1..h-1 {
            // 左枠
            print!("#");

            for _ in 1..w-1 {
                print!(".");
            }

            // 右枠
            print!("#");
            println!();
        }

        // 下枠
        for _ in 0..w {
            print!("#");
        }
        println!();
        println!();
    }
}
