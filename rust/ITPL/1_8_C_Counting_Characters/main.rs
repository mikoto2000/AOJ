use std::io::BufRead;

fn main() {

    let mut a = 0;
    let mut b = 0;
    let mut c = 0;
    let mut d = 0;
    let mut e = 0;
    let mut f = 0;
    let mut g = 0;
    let mut h = 0;
    let mut i = 0;
    let mut j = 0;
    let mut k = 0;
    let mut l = 0;
    let mut m = 0;
    let mut n = 0;
    let mut o = 0;
    let mut p = 0;
    let mut q = 0;
    let mut r = 0;
    let mut s = 0;
    let mut t = 0;
    let mut u = 0;
    let mut v = 0;
    let mut w = 0;
    let mut x = 0;
    let mut y = 0;
    let mut z = 0;

    loop {

        let mut line1 = String::new();
        let stdin = std::io::stdin();
        let mut handle = stdin.lock();
        let read = handle.read_line(&mut line1).ok();

        if read == Some(0) {
            break;
        }
        line1 = line1.trim().parse::<String>().ok().unwrap();
        line1 = line1.to_lowercase();


        for vv in line1.chars() {
            match vv {
                'a' => a = a + 1,
                'b' => b = b + 1,
                'c' => c = c + 1,
                'd' => d = d + 1,
                'e' => e = e + 1,
                'f' => f = f + 1,
                'g' => g = g + 1,
                'h' => h = h + 1,
                'i' => i = i + 1,
                'j' => j = j + 1,
                'k' => k = k + 1,
                'l' => l = l + 1,
                'm' => m = m + 1,
                'n' => n = n + 1,
                'o' => o = o + 1,
                'p' => p = p + 1,
                'q' => q = q + 1,
                'r' => r = r + 1,
                's' => s = s + 1,
                't' => t = t + 1,
                'u' => u = u + 1,
                'v' => v = v + 1,
                'w' => w = w + 1,
                'x' => x = x + 1,
                'y' => y = y + 1,
                'z' => z = z + 1,
                _ => {},
            };
        }
    }

    println!("a : {}", a);
    println!("b : {}", b);
    println!("c : {}", c);
    println!("d : {}", d);
    println!("e : {}", e);
    println!("f : {}", f);
    println!("g : {}", g);
    println!("h : {}", h);
    println!("i : {}", i);
    println!("j : {}", j);
    println!("k : {}", k);
    println!("l : {}", l);
    println!("m : {}", m);
    println!("n : {}", n);
    println!("o : {}", o);
    println!("p : {}", p);
    println!("q : {}", q);
    println!("r : {}", r);
    println!("s : {}", s);
    println!("t : {}", t);
    println!("u : {}", u);
    println!("v : {}", v);
    println!("w : {}", w);
    println!("x : {}", x);
    println!("y : {}", y);
    println!("z : {}", z);
}
