const std = @import("std");
const stdout = std.io.getStdOut().writer();
const common = @import("common");

fn digitSum(n: u1024) u64 {
    var n0: u1024 = n;
    var sum: u64 = 0;
    while (n0 != 0) : (n0 /= 10) {
        const digit = n0 % 10;
        sum += @intCast(digit);
    }

    return sum;
}

pub fn main() !void {
    const allocator = std.heap.page_allocator;
    var array = std.ArrayList(u64).init(allocator);
    defer array.deinit();

    for (1..100) |a| {
        for (1..100) |b| {
            const sum: u64 = digitSum(std.math.pow(u1024, a, b));
            try array.append(sum);
        }
    }

    try stdout.print("{}\n", .{common.maxList(u64, array)});
}
