use std::str::FromStr;

fn main() {
    loop {
        let mut stdin = String::new();
        std::io::stdin().read_line(&mut stdin).ok();
        stdin = stdin.trim().parse::<String>().ok().unwrap();

        if stdin == "0" {
            break;
        }

        let mut sum = 0;
        for v in stdin.chars() {
            let v = v.to_string();
            let x: u32 = FromStr::from_str(&v).unwrap();

            sum = sum + x;
        }

        println!("{}", sum);
    }
}
