use std::str::FromStr;

fn main() {
    loop {
        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let operation_number: u32 = FromStr::from_str(&line1[0]).unwrap();

        if operation_number == 0 {
            break;
        }

        // ダイス初期化
        let mut dice = init();
        let mut sum = 1;

        for _ in 0..operation_number {
            let mut line2 = String::new();
            std::io::stdin().read_line(&mut line2).ok();
            line2 = line2.trim().parse::<String>().ok().unwrap();
            let line2: Vec<&str> = line2.split_whitespace().collect();
            let operation: &str = &line2[0];

            dice = match operation {
                "North" => n(dice),
                "East" => e(dice),
                "South" => s(dice),
                "West" => w(dice),
                "Right" => r(dice),
                "Left" => l(dice),
                _ => panic!("unknown operation!"),
            };

            // println!("{:?}", dice);

            sum = sum + dice[0];
        }

        println!("{}", sum);
    }
}

fn init() -> Vec<u32> {
    return [1, 2, 3, 5, 4, 6].to_vec();
}

fn n(dice: Vec<u32>) -> Vec<u32> {
    //           1        2        3        5        4        6
    return [dice[1], dice[5], dice[2], dice[0], dice[4], dice[3]].to_vec();
}

fn s(dice: Vec<u32>) -> Vec<u32> {
    //           1        2        3        5        4        6
    return [dice[3], dice[0], dice[2], dice[5], dice[4], dice[1]].to_vec();
}

fn e(dice: Vec<u32>) -> Vec<u32> {
    //           1        2        3        5        4        6
    return [dice[4], dice[1], dice[0], dice[3], dice[5], dice[2]].to_vec();
}

fn w(dice: Vec<u32>) -> Vec<u32> {
    //           1        2        3        5        4        6
    return [dice[2], dice[1], dice[5], dice[3], dice[0], dice[4]].to_vec();
}

fn l(dice: Vec<u32>) -> Vec<u32> {
    //           1        2        3        5        4        6
    return [dice[0], dice[4], dice[1], dice[2], dice[3], dice[5]].to_vec();
}

fn r(dice: Vec<u32>) -> Vec<u32> {
    //           1        2        3        5        4        6
    return [dice[0], dice[2], dice[3], dice[4], dice[1], dice[5]].to_vec();
}
