const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn sumDigitsSquare(n: u64) u64 {
    var sum: u64 = 0;
    var ndigits: u64 = 0;
    var n0 = n;
    while (n0 != 0) : (n0 /= 10) {
        ndigits += 1;
    }

    n0 = n;
    while (ndigits != 0) : (ndigits -= 1) {
        const digit = n0 % 10;
        sum += digit*digit;
        n0 /= 10;
    }

    return sum;
}

fn solve(limit: u64) !u64 {
    const allocator = std.heap.page_allocator;
    var list = std.ArrayList(u64).init(allocator);
    defer list.deinit();

    var starting: u64 = 1;
    var n: u64 = starting;
    while (starting <= limit) {
        n = sumDigitsSquare(n);

        if (n == 1) {
            starting += 1;
            n = starting;
        }

        if (n == 89) {
            try list.append(starting);
            starting += 1;
            n = starting;
        }
    }

    return list.items.len;
}

pub fn main() !void {
    const solution = try solve(10000000);
    try stdout.print("{}\n", .{solution});
}
