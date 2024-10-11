use std::str::FromStr;
use std::collections::LinkedList;

fn main() {

    // q
    let mut lineline1 = String::new();
    std::io::stdin().read_line(&mut lineline1).ok();
    lineline1 = lineline1.trim().parse::<String>().ok().unwrap();
    let lineline1: LinkedList<&str> = lineline1.split_whitespace().collect();
    let q: u32 = FromStr::from_str(&lineline1[0]).unwrap();

    let mut list: LinkedList<u32> = LinkedList::new();

    let mut cursor = 0;
    for _ in 0..q {
        use std::str::FromStr;

        let mut lineline2 = String::new();
        std::io::stdin().read_line(&mut lineline2).ok();
        lineline2 = lineline2.trim().parse::<String>().ok().unwrap();
        let lineline2: LinkedList<&str> = lineline2.split_whitespace().collect();
        let o: u32 = FromStr::from_str(&lineline2[0]).unwrap();

        let n: i32 = if o != 2 {
            FromStr::from_str(&lineline2[1]).unwrap()
        } else {
            0
        };

        cursor = do_query(&mut list, cursor, o, n);
    }

    for e in list {
        println!("{}", e);
    }

}

fn do_query(list: &mut LinkedList<u32>, cursor: usize, operation: u32, number: i32) -> usize {
    match operation {
        0 => {
            list.insert(cursor, number as u32);
            return cursor;
        },
        1 => return (cursor as i32 + number) as usize,
        2 => {
            list.remove(cursor);
            return cursor;
        },
        _ => panic!("unknown operation.")
    }
}

