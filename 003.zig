const std = @import("std");
const stdout = std.io.getStdOut().writer();
const common = @import("common");

fn solve(n: u64) !u64 {
    const allocator = std.heap.page_allocator;
    var arr = std.ArrayList(u64).init(allocator);
    defer arr.deinit();
    var n0: u64 = n;

    while (n0 > 1) {
        var m = common.minDiv(n0);
        n0 /= m;
        try arr.append(m);
    }

    return common.maxList(u64, arr);
}

pub fn main() !void {
    const max: u64 = try solve(600851475143);
    try stdout.print("{}\n", .{max});
}
