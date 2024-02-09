const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn sum_digits_square(n: u64) u64 {
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
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    var allocator = gpa.allocator();
    defer _ = gpa.deinit();
    var list = std.ArrayList(u64).init(allocator);
    defer list.deinit();

    var starting: u64 = 1;
    var n: u64 = starting;
    while (starting <= limit) {
        n = sum_digits_square(n);

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
    try stdout.print("{!}\n", .{solve(10000000)});
}
