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
            break;
        }

        for vh in 0..h {
            let vhd = vh % 2;
            for vw in 0..w {
                let print_char = if (vw + vhd) % 2 == 0 {
                    "#"
                } else {
                    "."
                };
                print!("{}", print_char);
            }
            println!();
        }
        println!();
    }
}
