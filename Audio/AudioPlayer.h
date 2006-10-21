/*
 *  $Id$
 *
 *  Copyright (C) 2006 Stephen F. Booth <me@sbooth.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#import <Cocoa/Cocoa.h>
#include <AudioToolbox/AudioFormat.h>
#include <AudioUnit/AudioUnit.h>
#import "AudioStreamDecoder.h"

@class LibraryDocument;

@interface AudioPlayer : NSObject
{
	AudioUnit				_audioUnit;
	AudioStreamDecoder		*_streamDecoder;
	
	LibraryDocument			*_owner;
	
	BOOL					_isPlaying;
	SInt64					_frameCountAccumulator;		// Accumulator value for UI updates
}

- (BOOL)				setStreamDecoder:(AudioStreamDecoder *)streamDecoder error:(NSError **)error;
- (void)				reset;

- (void)				play;
- (void)				playPause;
- (void)				stop;

- (BOOL)				isPlaying;

// The following methods are only updated approximately once per second to avoid excessive CPU loads
// To truly observe the values use the streamDecoder
- (SInt64)				totalFrames;

- (SInt64)				currentFrame;
- (void)				setCurrentFrame:(SInt64)currentFrame;

- (NSString *)			totalSecondsString;
- (NSString *)			currentSecondString;
- (NSString *)			secondsRemainingString;

@end