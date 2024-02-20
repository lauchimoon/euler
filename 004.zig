const std = @import("std");
const stdout = std.io.getStdOut().writer();
const common = @import("common");

fn isPalindrome(n: u64) bool {
    var reverse: u64 = 0;
    var n0: u64 = n;
    while (n0 != 0) {
        reverse = (reverse * 10) + (@mod(n0, 10));
        n0 /= 10;
    }

    return reverse == n;
}

fn solve(start: u64, end: u64) !u64 {
    const allocator = std.heap.page_allocator;

    var palindromes = std.ArrayList(u64).init(allocator);
    defer palindromes.deinit();

    for (start..end) |i| {
        for (start..end) |j| {
            var prod: usize = i * j;
            if (isPalindrome(prod)) {
                try palindromes.append(prod);
            }
        }
    }

    return common.maxList(u64, palindromes);
}

pub fn main() !void {
    const max = try solve(100, 999);
    try stdout.print("{}\n", .{max});
}
