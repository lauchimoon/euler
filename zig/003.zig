const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn is_prime(n: u64) bool {
    for (2..n) |i| {
        if (@mod(n, i) == 0) {
            return false;
        }
    }

    return true;
}

fn max_list(list: std.ArrayList(u64)) u64 {
    var m: u64 = 0;
    for (list.items) |item| {
        m = @max(m, item);
    }

    return m;
}

fn solve(n: u64) anyerror!u64 {
    const allocator = std.heap.page_allocator;
    var factors = std.ArrayList(u64).init(allocator);
    defer factors.deinit();

    for (2..n - 1) |i| {
        if (i > 1000000) {
            break;
        }
        if (@mod(n, i) == 0 and is_prime(i)) {
            try factors.append(i);
        }
    }

    const max = max_list(factors);
    return max;
}

pub fn main() !void {
    const max: anyerror!u64 = solve(600851475143);
    try stdout.print("{!}\n", .{max});
}
