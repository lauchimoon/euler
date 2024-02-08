const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn is_palindrome(n: u64) bool {
    var reverse: u64 = 0;
    var n0: u64 = n;
    while (n0 != 0) {
        reverse = (reverse * 10) + (@mod(n0, 10));
        n0 /= 10;
    }

    return reverse == n;
}

fn max_list(list: std.ArrayList(u64)) u64 {
    var m: u64 = 0;
    for (list.items) |item| {
        m = @max(m, item);
    }

    return m;
}

fn solve(start: u64, end: u64) anyerror!u64 {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    var palindromes = std.ArrayList(u64).init(allocator);
    defer palindromes.deinit();

    for (start..end) |i| {
        for (start..end) |j| {
            var prod: usize = i * j;
            if (is_palindrome(prod)) {
                try palindromes.append(prod);
            }
        }
    }

    const max = max_list(palindromes);
    return max;
}

pub fn main() !void {
    const max = solve(100, 999);
    try stdout.print("{!}\n", .{max});
}
