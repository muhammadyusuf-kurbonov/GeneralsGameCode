#pragma once

//-------------------------------------------------------------------------------------------------
/** LOD values for terrain, keep this in sync with TerrainLODNames[] */
//-------------------------------------------------------------------------------------------------
typedef enum _TerrainLOD
{ 
	TERRAIN_LOD_INVALID								= 0,
	TERRAIN_LOD_MIN										= 1,  // note that this is less than max
	TERRAIN_LOD_STRETCH_NO_CLOUDS			= 2,
	TERRAIN_LOD_HALF_CLOUDS						= 3,
	TERRAIN_LOD_NO_CLOUDS							= 4,
	TERRAIN_LOD_STRETCH_CLOUDS				= 5,
	TERRAIN_LOD_NO_WATER							= 6,
	TERRAIN_LOD_MAX										= 7,  // note that this is larger than min
	TERRAIN_LOD_AUTOMATIC							= 8,
	TERRAIN_LOD_DISABLE								= 9,

	TERRAIN_LOD_NUM_TYPES								// keep this last

} TerrainLOD;

static const char * TerrainLODNames[] = 
{
	"NONE",
	"MIN",
	"STRETCH_NO_CLOUDS",
	"HALF_CLOUDS",
	"NO_CLOUDS",
	"STRETCH_CLOUDS",
	"NO_WATER",
	"MAX",
	"AUTOMATIC",
	"DISABLE",

	NULL
};