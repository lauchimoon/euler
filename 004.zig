const std = @import("std");
const stdout = std.io.getStdOut().writer();
const common = @import("common");

fn solve(start: u64, end: u64) !u64 {
    const allocator = std.heap.page_allocator;

    var palindromes = std.ArrayList(u64).init(allocator);
    defer palindromes.deinit();

    for (start..end) |i| {
        for (start..end) |j| {
            var prod: usize = i * j;
            if (common.isPalindrome(prod)) {
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
