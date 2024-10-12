fn main() {
    use std::str::FromStr;

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let n: u32 = FromStr::from_str(&line1[0]).unwrap();


    for i in 1..n+1 {

        // 3 の倍数
        if i % 3 == 0 {
            print!(" {}", i);
            continue;
        }

        // 3 が含まれている
        let mut ii = i;
        while ii >= 3 {
            if ii % 10 == 3 {
                print!(" {}", i);
                break;
            }
            ii = ii / 10;
        }
    }
    println!();
}
