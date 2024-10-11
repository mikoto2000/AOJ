use std::collections::HashMap;

use std::str::FromStr;

fn main() {
    loop {
        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let replace_number: u32 = FromStr::from_str(&line1[0]).unwrap();

        if replace_number == 0 {
            break;
        }

        let mut map = HashMap::new();

        for _ in 0..replace_number {
            let mut line2 = String::new();
            std::io::stdin().read_line(&mut line2).ok();
            line2 = line2.trim().parse::<String>().ok().unwrap();
            let line2: Vec<&str> = line2.split_whitespace().collect();
            let before: String = (&line2[0]).to_string();
            let after: String = (&line2[1]).to_string();

            map.insert(before, after);
        }

        let mut line3 = String::new();
        std::io::stdin().read_line(&mut line3).ok();
        line3 = line3.trim().parse::<String>().ok().unwrap();
        let line3: Vec<&str> = line3.split_whitespace().collect();
        let char_number: u32 = FromStr::from_str(&line3[0]).unwrap();

        for _ in 0..char_number {
            let mut line4 = String::new();
            std::io::stdin().read_line(&mut line4).ok();
            line4 = line4.trim().parse::<String>().ok().unwrap();
            let line4: Vec<&str> = line4.split_whitespace().collect();
            let c: String = (&line4[0]).to_string();

            let mut converted_c: String = c.clone();

            for (k, v) in &map {
                if *k == c {
                    converted_c = v.to_string();
                    break;
                }
            }

            print!("{}", converted_c);
        }

        println!();
    }
}
