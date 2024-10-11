fn main() {

    let mut line = String::new();
    while std::io::stdin().read_line(&mut line).unwrap() > 0 {
        let target_number: usize = line.trim().parse::<usize>().unwrap();

        let mut prime_count = 0;
        for n in 1..target_number+1 {

            // 素数判定して数値をインクリメント
            if is_prime(n) {
                prime_count +=1;
            }
        }

        println!("{}", prime_count);

        line.clear();
    }
}

fn is_prime(target_number: usize) -> bool {
   if target_number == 1 { return false; }
   if target_number == 2 { return true; }
   if target_number == 3 { return true; }
   if target_number == 4 { return false; }
   if target_number == 5 { return true; }

   // 半分以上では確実に割れ無いのでスキップ
   // こっちだとすごい時間かかる
   let to = (target_number/2)+1;

   // 1,2 は評価済み
   // 3 から対象数値のルート2までに割り切れる数が無ければ素数
   //let to = (target_number as f64).sqrt() as usize;
   for n in (3..to).step_by(2) {
       //println!("{} % {} = {}", target_number, n, target_number % n);
       if target_number % n == 0 {
           return false;
       }
   }
   return true;
}
