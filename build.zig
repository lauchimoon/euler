const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = std.zig.CrossTarget{ .os_tag = .linux, .cpu_arch = .x86_64 };
    const file = b.option([]const u8, "problem", "Get the solution for a specific problem") orelse "001.zig";

    const exe = b.addExecutable(.{
        .name = "solution",
        .root_source_file = .{ .path = file },
        .target = target,
    });
    const common = b.addModule("common", .{.source_file = .{.path = "./common/common.zig"}});

    b.installArtifact(exe);
    exe.addModule("common", common);

    const run = b.addRunArtifact(exe);
    const run_step = b.step("run", "Run the application");
    run_step.dependOn(&run.step);
}
