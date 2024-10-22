fn main() {

    let mut stdin = String::new();
    std::io::stdin().read_line(&mut stdin).ok();
    stdin = stdin.trim().parse::<String>().ok().unwrap();

    for v in stdin.chars() {
        let v = v.to_string();
        let v = v.as_str();
        print!("{}", match v {
            "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z" => v.to_uppercase(),
            "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z" => v.to_lowercase(),
            _ => v.to_string(),
        })
    }
    println!()
}
