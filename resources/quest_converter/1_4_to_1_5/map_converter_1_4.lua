-- Solarus 1.4 to 1.5.
-- Changes in the map syntax:
-- - New mandatory properties min_layer and max_layer.
-- - The rank property of enemies no longer exists.

local converter = {}

function converter.convert(quest_path, map_id, default_font_id)

  local input_file_name = quest_path .. "/data/maps/" .. map_id .. ".dat"
  local input_file, error_message = io.open(input_file_name)
  if input_file == nil then
    error("Cannot open old map file for reading: " .. error_message)
  end

  local text = input_file:read("*a")  -- Read the whole file.

  -- Add the min_layer and max_layer properties.
  text = text:gsub(
      "\n  tileset = \"",
      "\n  min_layer = 0,\n  max_layer = 2,\n  tileset = \""
  )

  -- Remove the rank property of enemies.
  text = text:gsub(
      "\n  rank = [0-2],",
      ""
  )

  input_file:close()

  local output_file_name = input_file_name
  local output_file, error_message = io.open(output_file_name, "w")
  if output_file == nil then
    error("Cannot open new map file for writing: " .. error_message)
  end

  output_file:write(text)
  output_file:close()
end

return converter

