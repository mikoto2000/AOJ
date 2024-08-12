use std::str::FromStr;

fn main() {
    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let vert_count: u32 = FromStr::from_str(&line1[0]).unwrap();

    for _ in 1..vert_count + 1 {
        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();
        let line2: Vec<&str> = line2.split_whitespace().collect();
        //let vert_number: u32 = FromStr::from_str(&line2[0]).unwrap();
        //let dju_count: u32 = FromStr::from_str(&line2[1]).unwrap();
        let dju: Vec<u32> = line2[2..]
            .to_vec()
            .into_iter()
            .map(|e| FromStr::from_str(&e).unwrap())
            .collect();

        // println!("{}, {}, {:?}", vert_number, dju_count, dju);

        let mut row = vec![];
        for i in 1..vert_count + 1 {
            if dju.contains(&i) {
                row.push(1.to_string())
            } else {
                row.push(0.to_string())
            }
        }
        println!("{}", row.join(" "));
    }
}
