const std = @import("std");
const stdout = std.io.getStdOut().writer();
const data = @embedFile("./resources/0022_names.txt");

fn compareStrings(_: void, lhs: []const u8, rhs: []const u8) bool {
    return std.mem.order(u8, lhs, rhs).compare(std.math.CompareOperator.lt);
}

fn splitStr(str: []const u8, delimiter: []const u8, allocator: std.mem.Allocator) !std.ArrayList([]const u8) {
    var list = std.ArrayList([]const u8).init(allocator);
    var split = std.mem.split(u8, str, delimiter);
    while (split.next()) |item| {
        try list.append(item);
    }

    return list;
}

fn nameScore(name: []const u8, index: u64) u64 {
    var score: u64 = 0;

    for (1..name.len - 1) |i| {
        const a: u64 = 65;
        const idx: u64 = @intCast(name[i]);
        const letter = idx - a + 1;
        score += letter;
    }

    score *= index;
    return score;
}

fn solve() !u64 {
    const allocator = std.heap.page_allocator;
    var split = try splitStr(data, ",", allocator);
    defer split.deinit();

    std.sort.insertion([]const u8, split.items, {}, compareStrings);

    var total: u64 = 0;

    for (split.items, 0..) |name, i| {
        total += nameScore(name, i + 1);
    }

    return total;
}

pub fn main() !void {
    try stdout.print("{}\n", .{try solve()});
}
